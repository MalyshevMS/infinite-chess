#pragma once

#include "piece.hpp"

namespace infChess {
    namespace Pieces {
        class Pawn : public Piece {
        public:
            Pawn(Color color) : Piece("res/pawn.png", color) {}

            bool move(class Board& board, sf::Vector2i offset) override;
        };
    }
}