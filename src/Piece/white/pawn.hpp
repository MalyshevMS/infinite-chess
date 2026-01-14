#pragma once

#include "../piece.hpp"

namespace infChess {
    namespace Pieces {
        namespace White {
            class Pawn : public Piece {
            public:
                Pawn(class Board& board) : Piece(board, "res/pawn-white.png") {}
    
                bool move(sf::Vector2i offset) override;
            };
        }
    }
}