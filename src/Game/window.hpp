#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <functional>
#include "camera.hpp"
#include "../Board/board.hpp"

namespace infChess {
    class Window {
    private:
        sf::RenderWindow window;
        sf::View view;
        sf::Clock clock;

        Camera* camera;

        float deltaTime;
    public:
        /// Callback functions

        std::function<void(const sf::Event::Closed*)> __cb_Closed = nullptr;
        std::function<void(const sf::Event::FocusGained*)> __cb_FocusGained = nullptr;
        std::function<void(const sf::Event::FocusLost*)> __cb_FocusLost = nullptr;
        std::function<void(const sf::Event::JoystickButtonPressed*)> __cb_JoystickButtonPressed = nullptr;
        std::function<void(const sf::Event::JoystickButtonReleased*)> __cb_JoystickButtonReleased = nullptr;
        std::function<void(const sf::Event::JoystickConnected*)> __cb_JoystickConnected = nullptr;
        std::function<void(const sf::Event::JoystickDisconnected*)> __cb_JoystickDisconnected = nullptr;
        std::function<void(const sf::Event::JoystickMoved*)> __cb_JoystickMoved = nullptr;
        std::function<void(const sf::Event::KeyPressed*)> __cb_KeyPressed = nullptr;
        std::function<void(const sf::Event::KeyReleased*)> __cb_KeyReleased = nullptr;
        std::function<void(const sf::Event::MouseButtonPressed*)> __cb_MouseButtonPressed = nullptr;
        std::function<void(const sf::Event::MouseButtonReleased*)> __cb_MouseButtonReleased = nullptr;
        std::function<void(const sf::Event::MouseEntered*)> __cb_MouseEntered = nullptr;
        std::function<void(const sf::Event::MouseLeft*)> __cb_MouseLeft = nullptr;
        std::function<void(const sf::Event::MouseMoved*)> __cb_MouseMoved = nullptr;
        std::function<void(const sf::Event::MouseMovedRaw*)> __cb_MouseMovedRaw = nullptr;
        std::function<void(const sf::Event::MouseWheelScrolled*)> __cb_MouseWheelScrolled = nullptr;
        std::function<void(const sf::Event::Resized*)> __cb_Resized = nullptr;
        std::function<void(const sf::Event::SensorChanged*)> __cb_SensorChanged = nullptr;
        std::function<void(const sf::Event::TextEntered*)> __cb_TextEntered = nullptr;
        std::function<void(const sf::Event::TouchBegan*)> __cb_TouchBegan = nullptr;
        std::function<void(const sf::Event::TouchEnded*)> __cb_TouchEnded = nullptr;

        std::function<void(const sf::Event::TouchMoved*)> __cb_TouchMoved = nullptr;
        Window(sf::VideoMode mode, std::string title, bool fullscreen);
        sf::RenderWindow* nativeHandle() { return &window; }

        void draw(Drawable& target);
        float getDeltaTime() { return deltaTime; };
        bool isKeyPressed(sf::Keyboard::Key key);
        sf::Vector2i getMousePos();
        void callback(const std::optional<sf::Event>&& event);
        void bindCamera(Camera& other);
        sf::Vector2f screenToWorld(sf::Vector2f screen, const Camera& cam );

        void frameStart();
        void close() { window.close(); }
        bool isOpen();
        void frameEnd() { window.display(); }
    };
}