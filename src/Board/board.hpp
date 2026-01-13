#pragma once

#include "boardTexture.hpp"
#include "boardSprite.hpp"
#include "../Game/drawable.hpp"
#include "../Piece/piece.hpp"

namespace infChess {
    class Board : public Drawable {
    private:
        BoardSprite sprite;
        
        std::vector<Piece> whites = {};
        std::vector<Piece> blacks = {};
    public:
        Board(bool drawBorders = false);
        void drawOn(sf::RenderTarget& surface) override;

        bool isFree(sf::Vector2i position);

        static const int cell = 100;
        static const int board = cell * 8;
    };
}