#include "piece.hpp"
#include "../Board/board.hpp"

infChess::Piece::Piece(class Board& board, std::string texturePath)
 : sprite(texture), pBoard(&board) {
    if (!texture.loadFromFile(texturePath)) return;
    texture.setSmooth(true);
    
    sprite.setTexture(texture, true);

    auto bounds = sprite.getLocalBounds();

    sprite.setScale({
        Board::cell / bounds.size.x,
        Board::cell / bounds.size.y
    });
}

bool infChess::Piece::move(sf::Vector2i offset) {
    sprite.move(sf::Vector2f(board.cell * offset));
    return true;
}

void infChess::Piece::drawOn(sf::RenderTarget &surface) {
    surface.draw(sprite);
}

sf::Vector2i infChess::Piece::getPosition() {
    return position;
}