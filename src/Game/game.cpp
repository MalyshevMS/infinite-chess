#include "game.hpp"
#include <algorithm>

void infChess::Game::run() {
    Window window = Window(sf::VideoMode::getDesktopMode(), "Infinite Chess", true);

    Board board(true);

    Camera cam;
    cam.pos = { Board::board / 2.f, Board::board / 2.f};
    cam.speed = 1'000.f;
    cam.mag = 1.75f;
    cam.zoomBase = 1.1f;

    window.bindCamera(cam);

    window.__cb_MouseWheelScrolled = [&](const sf::Event::MouseWheelScrolled* info){
        if (info->wheel == sf::Mouse::Wheel::Vertical) {
            cam.mag *= std::pow(cam.zoomBase, info->delta);
            cam.mag = std::clamp(cam.mag, 0.1f, 5.f);
        }
    };

    while(window.isOpen()) {
        window.frameStart();

        const auto dt = window.getDeltaTime();

        window.draw(board);

        if (window.isKeyPressed(sf::Keyboard::Key::Escape)) window.close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            cam.y -= cam.speed * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            cam.y += cam.speed * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            cam.x -= cam.speed * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            cam.x += cam.speed * dt;

        window.frameEnd();
    }
}