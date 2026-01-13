#include "board.hpp"

infChess::Board::Board(bool drawBorders) : sprite(8'000'000, cell, 8, drawBorders) {

}

void infChess::Board::drawOn(sf::RenderTarget& surface) {
    sprite.drawOn(surface);
}

bool infChess::Board::isFree(sf::Vector2i position) {
    for (auto w : whites) {
        if (w.getPosition() == position) return false;
    }

    for (auto b : blacks) {
        if (b.getPosition() == position) return false;
    }

    return true;
}
