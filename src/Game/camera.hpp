#pragma once

#include <SFML/System/Vector2.hpp>

namespace infChess {
    struct Camera {
        sf::Vector2f pos = {0.f, 0.f};
        float speed = 0.f;
        float mag = 0.f;
        float zoomBase = 0.f;

        float& x = pos.x;
        float& y = pos.y;
    };
}