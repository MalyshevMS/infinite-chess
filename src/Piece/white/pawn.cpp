#include "pawn.hpp"
#include "../../Board/board.hpp"

bool infChess::Pieces::White::Pawn::move(sf::Vector2i offset) {
    const bool free = board.isFree(position + offset);
    if (
        free && offset == sf::Vector2i(0, -1) || // moving forward
        free && position.y == -7 && offset == sf::Vector2i(0, -2) || // first move can be (0, -2)
        !free && (offset == sf::Vector2i(1, -1) || offset == sf::Vector2i(-1, -1)) // eating other piece
    ) {
        if (!free) board.eat(position + offset, true);
        return Piece::move(offset);
    } else return false;
}