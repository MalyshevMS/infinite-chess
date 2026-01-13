#include "pawn.hpp"
#include "../Board/board.hpp"

bool infChess::Pieces::Pawn::move(Board& board, sf::Vector2i offset) {
    if (!board.isFree(position + offset) && \
        offset != sf::Vector2i{1, 1} && \
        offset != sf::Vector2i{-1, 1}) return false;
    
        return Piece::move(board, offset);
}