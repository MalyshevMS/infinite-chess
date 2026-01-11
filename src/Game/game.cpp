#include "game.hpp"
#include <algorithm>

void infChess::Game::run() {
    Window window = Window(sf::VideoMode::getDesktopMode(), "Infinite Chess", true);

    Board board(true);

    Camera cam;
    cam.pos = { Board::board / 2.f, Board::board / 2.f};
    cam.speed = 1'000.f;
    cam.mag = 1.f;
    cam.zoomBase = 1.1f;

    window.bindCamera(cam);

    window.__cb_MouseWheelScrolled = [&](const sf::Event::MouseWheelScrolled* info){
        if (info->wheel != sf::Mouse::Wheel::Vertical) return;

        const sf::Vector2f mouseScreen = { (float)window.getMousePos().x, (float)window.getMousePos().y };
        const sf::Vector2f before = window.screenToWorld(mouseScreen, cam);

        cam.mag *= std::pow(cam.zoomBase, info->delta);
        cam.mag = std::clamp(cam.mag, 0.1f, 5.f);

        const sf::Vector2f after = window.screenToWorld(mouseScreen, cam);

        cam.pos += (before - after);
    };

    while(window.isOpen()) {
        window.frameStart();

        const auto dt = window.getDeltaTime();

        window.draw(board);

        if (window.isKeyPressed(sf::Keyboard::Key::Escape)) window.close();

        const float move = cam.speed * dt / cam.mag;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            cam.y -= move;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            cam.y += move;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            cam.x -= move;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            cam.x += move;

        window.frameEnd();
    }
}