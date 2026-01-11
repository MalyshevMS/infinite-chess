#include "window.hpp"

infChess::Window::Window(sf::VideoMode mode, std::string title, bool fullscreen) {
    window.create(std::move(mode), std::move(title), fullscreen ? sf::State::Fullscreen : sf::State::Windowed);
    view = window.getDefaultView();
    clock = sf::Clock();

    window.setFramerateLimit(60);

    camera = new Camera;
}

void infChess::Window::draw(Drawable& target) {
    target.drawOn(window);
}

bool infChess::Window::isKeyPressed(sf::Keyboard::Key key)
{
    return sf::Keyboard::isKeyPressed(key);
}

bool infChess::Window::isOpen()
{
    return window.isOpen();
}

void infChess::Window::frameStart() {
    deltaTime = clock.restart().asSeconds();

    while (auto event = window.pollEvent()) {
        callback(std::move(event));
    }

    view.setCenter(camera->pos);
    view.setSize(window.getDefaultView().getSize() * (1 / camera->mag));
    
    window.setView(view);
    window.clear(sf::Color::Cyan);
}

void infChess::Window::bindCamera(Camera& other) {
    if (camera) delete camera;
    camera = &other;
}