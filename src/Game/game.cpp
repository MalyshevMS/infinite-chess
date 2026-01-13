#include "game.hpp"
#include "../Piece/pawn.hpp"
#include <algorithm>

void infChess::Game::run() {
    Window window = Window(sf::VideoMode::getDesktopMode(), "Infinite Chess", true);

    Board board(true);
    Pieces::Pawn p1(Piece::Color::White);

    Camera cam;
    cam.pos = { Board::board / 2.f, Board::board / 2.f};
    cam.speed = 1'000.f;
    cam.mag = 1.f;
    cam.zoomBase = 1.1f;

    window.bindCamera(cam);

    window.__cb_MouseWheelScrolled = [&](const sf::Event::MouseWheelScrolled* info){
        if (info->wheel != sf::Mouse::Wheel::Vertical) return;

        const sf::Vector2f mouseScreen = window.getMousePos();
        const sf::Vector2f before = window.screenToWorld(mouseScreen);

        cam.mag *= std::pow(cam.zoomBase, info->delta);
        cam.mag = std::clamp(cam.mag, 0.1f, 5.f);

        const sf::Vector2f after = window.screenToWorld(mouseScreen);

        cam.pos += (before - after);
    };

    window.__cb_KeyPressed = [&](const sf::Event::KeyPressed* info){
        if (info->code == sf::Keyboard::Key::E) p1.move(board, {0, -1});
    };

    while(window.isOpen()) {
        window.frameStart();

        const auto dt = window.getDeltaTime();

        window.draw(board);
        window.draw(p1);

        if (window.isKeyPressed(sf::Keyboard::Key::Escape)) window.close();

        const float move = cam.speed * dt / cam.mag;
        if (window.isKeyPressed(sf::Keyboard::Key::W))
            cam.y -= move;
        if (window.isKeyPressed(sf::Keyboard::Key::S))
            cam.y += move;
        if (window.isKeyPressed(sf::Keyboard::Key::A))
            cam.x -= move;
        if (window.isKeyPressed(sf::Keyboard::Key::D))
            cam.x += move;
        if (window.isButtonPressed(sf::Mouse::Button::Middle)) {
            cam.pos += window.getDeltaCursor() / cam.mag;
        }

        window.frameEnd();
    }
}