#include "window.hpp"

void infChess::Window::callback(const std::optional<sf::Event>&& event) {
    if (event->is<sf::Event::Closed>()) {
        window.close();
        const auto info = event->getIf<sf::Event::Closed>();
        if (__cb_Closed) __cb_Closed(info);
    }

    if (event->is<sf::Event::FocusGained>()) {
        const auto info = event->getIf<sf::Event::FocusGained>();
        if (__cb_FocusGained) __cb_FocusGained(info);
    }

    if (event->is<sf::Event::FocusLost>()) {
        const auto info = event->getIf<sf::Event::FocusLost>();
        if (__cb_FocusLost) __cb_FocusLost(info);
    }

    if (event->is<sf::Event::JoystickButtonPressed>()) {
        const auto info = event->getIf<sf::Event::JoystickButtonPressed>();
        if (__cb_JoystickButtonPressed) __cb_JoystickButtonPressed(info);
    }

    if (event->is<sf::Event::JoystickButtonReleased>()) {
        const auto info = event->getIf<sf::Event::JoystickButtonReleased>();
        if (__cb_JoystickButtonReleased) __cb_JoystickButtonReleased(info);
    }

    if (event->is<sf::Event::JoystickConnected>()) {
        const auto info = event->getIf<sf::Event::JoystickConnected>();
        if (__cb_JoystickConnected) __cb_JoystickConnected(info);
    }

    if (event->is<sf::Event::JoystickDisconnected>()) {
        const auto info = event->getIf<sf::Event::JoystickDisconnected>();
        if (__cb_JoystickDisconnected) __cb_JoystickDisconnected(info);
    }

    if (event->is<sf::Event::JoystickMoved>()) {
        const auto info = event->getIf<sf::Event::JoystickMoved>();
        if (__cb_JoystickMoved) __cb_JoystickMoved(info);
    }

    if (event->is<sf::Event::KeyPressed>()) {
        const auto info = event->getIf<sf::Event::KeyPressed>();
        if (__cb_KeyPressed) __cb_KeyPressed(info);
    }

    if (event->is<sf::Event::KeyReleased>()) {
        const auto info = event->getIf<sf::Event::KeyReleased>();
        if (__cb_KeyReleased) __cb_KeyReleased(info);
    }

    if (event->is<sf::Event::MouseButtonPressed>()) {
        const auto info = event->getIf<sf::Event::MouseButtonPressed>();
        if (__cb_MouseButtonPressed) __cb_MouseButtonPressed(info);
    }

    if (event->is<sf::Event::MouseButtonReleased>()) {
        const auto info = event->getIf<sf::Event::MouseButtonReleased>();
        if (__cb_MouseButtonReleased) __cb_MouseButtonReleased(info);
    }

    if (event->is<sf::Event::MouseEntered>()) {
        const auto info = event->getIf<sf::Event::MouseEntered>();
        if (__cb_MouseEntered) __cb_MouseEntered(info);
    }

    if (event->is<sf::Event::MouseLeft>()) {
        const auto info = event->getIf<sf::Event::MouseLeft>();
        if (__cb_MouseLeft) __cb_MouseLeft(info);
    }

    if (event->is<sf::Event::MouseMoved>()) {
        const auto info = event->getIf<sf::Event::MouseMoved>();
        if (__cb_MouseMoved) __cb_MouseMoved(info);
    }

    if (event->is<sf::Event::MouseMovedRaw>()) {
        const auto info = event->getIf<sf::Event::MouseMovedRaw>();
        if (__cb_MouseMovedRaw) __cb_MouseMovedRaw(info);
    }

    if (event->is<sf::Event::MouseWheelScrolled>()) {
        const auto info = event->getIf<sf::Event::MouseWheelScrolled>();
        if (__cb_MouseWheelScrolled) __cb_MouseWheelScrolled(info);
    }

    if (event->is<sf::Event::Resized>()) {
        const auto info = event->getIf<sf::Event::Resized>();
        if (__cb_Resized) __cb_Resized(info);
    }

    if (event->is<sf::Event::SensorChanged>()) {
        const auto info = event->getIf<sf::Event::SensorChanged>();
        if (__cb_SensorChanged) __cb_SensorChanged(info);
    }

    if (event->is<sf::Event::TextEntered>()) {
        const auto info = event->getIf<sf::Event::TextEntered>();
        if (__cb_TextEntered) __cb_TextEntered(info);
    }

    if (event->is<sf::Event::TouchBegan>()) {
        const auto info = event->getIf<sf::Event::TouchBegan>();
        if (__cb_TouchBegan) __cb_TouchBegan(info);
    }

    if (event->is<sf::Event::TouchEnded>()) {
        const auto info = event->getIf<sf::Event::TouchEnded>();
        if (__cb_TouchEnded) __cb_TouchEnded(info);
    }

    if (event->is<sf::Event::TouchMoved>()) {
        const auto info = event->getIf<sf::Event::TouchMoved>();
        if (__cb_TouchMoved) __cb_TouchMoved(info);
    }
}