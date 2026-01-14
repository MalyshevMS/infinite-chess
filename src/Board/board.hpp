#pragma once

#include "boardTexture.hpp"
#include "boardSprite.hpp"
#include "../Game/drawable.hpp"
#include "../Piece/piece.hpp"
#include <list>

namespace infChess {
    class Board : public Drawable {
    private:
        BoardSprite sprite;
        
        std::list<Piece> whites = {};
        std::list<Piece> blacks = {};
    public:
        Board(bool drawBorders = false);
        void drawOn(sf::RenderTarget& surface) override;

        bool isFree(sf::Vector2i position);
        bool eat(sf::Vector2i position, bool isWhite);

        static const int cell = 100;
        static const int board = cell * 8;
    };
}