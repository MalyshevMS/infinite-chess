#pragma once

#include "boardTexture.hpp"

namespace infChess {
    class BoardSprite {
    private:
        BoardTexture texture;
        sf::Sprite* sprite = nullptr;
    public:
        BoardSprite(const int spriteSize, const int cellSize = 100, const int cells = 8, bool drawBorders = false);
        void drawOn(sf::RenderTarget& surface);
    };
}