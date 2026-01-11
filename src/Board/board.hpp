#pragma once

#include "boardTexture.hpp"
#include "boardSprite.hpp"
#include "../Game/drawable.hpp"

namespace infChess {
    class Board : public Drawable {
    private:
        BoardSprite sprite;
    public:
        Board(bool drawBorders = false);
        void drawOn(sf::RenderTarget& surface) override;

        static const int cell = 100;
        static const int board = cell * 8;
    };
}