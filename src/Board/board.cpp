#include "board.hpp"
#include <algorithm>

infChess::Board::Board(bool drawBorders) : sprite(8'000'000, cell, 8, drawBorders) {

}

void infChess::Board::drawOn(sf::RenderTarget& surface) {
    sprite.drawOn(surface);
}

bool infChess::Board::isFree(sf::Vector2i position) {
    for (auto& w : whites) {
        if (w.getPosition() == position) return false;
    }

    for (auto& b : blacks) {
        if (b.getPosition() == position) return false;
    }

    return true;
}

bool infChess::Board::eat(sf::Vector2i position, bool isWhite) {
    if (!isWhite) {
        for (auto i = whites.begin(); i != whites.end(); i++) {
            if (i->getPosition() == position) {
                whites.erase(i);
                return true;
            }
        }

        return false;
    } else {
        for (auto i = blacks.begin(); i != blacks.end(); i++) {
            if (i->getPosition() == position) {
                blacks.erase(i);
                return true;
            }
        }

        return false;
    }
}
