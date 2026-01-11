#pragma once

#include <SFML/Graphics/RenderTarget.hpp>

namespace infChess {
    class Drawable {
    public:
        virtual void drawOn(sf::RenderTarget&) = 0;
    };
}