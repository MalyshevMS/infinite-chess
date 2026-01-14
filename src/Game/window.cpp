#include "window.hpp"

infChess::Window::Window(sf::VideoMode mode, std::string title, bool fullscreen) {
    window.create(std::move(mode), std::move(title), fullscreen ? sf::State::Fullscreen : sf::State::Windowed);
    view = window.getDefaultView();
    clock = sf::Clock();

    window.setFramerateLimit(144);

    camera = new Camera;
}

void infChess::Window::draw(Drawable& target) {
    target.drawOn(window);
}

bool infChess::Window::isKeyPressed(sf::Keyboard::Key key) {
    return sf::Keyboard::isKeyPressed(key);
}

bool infChess::Window::isButtonPressed(sf::Mouse::Button button) {
    return sf::Mouse::isButtonPressed(button);
}

void infChess::Window::setCursor(sf::Cursor::Type type) {
    auto cursor = sf::Cursor::createFromSystem(type);
    if (cursor)
    window.setMouseCursor(*cursor);
}

sf::Vector2f infChess::Window::getMousePos() {
    return { (float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y};
}

bool infChess::Window::isOpen(){
    return window.isOpen();
}

void infChess::Window::frameStart() {
    deltaTime = clock.restart().asSeconds();

    currentCursor = getMousePos();
    deltaCursor = lastCursor - currentCursor;
    lastCursor = currentCursor;

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

sf::Vector2f infChess::Window::screenToWorld(sf::Vector2f screen) {
    sf::Vector2f size = { (float)window.getSize().x, (float)window.getSize().y };
    sf::Vector2f centered = screen - size * 0.5f;

    return camera->pos + centered / camera->mag;
}
