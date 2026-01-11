#include "board.hpp"

infChess::Board::Board(bool drawBorders) : sprite(8'000'000, cell, 8, drawBorders) {

}

void infChess::Board::drawOn(sf::RenderTarget& surface) {
    sprite.drawOn(surface);
}
