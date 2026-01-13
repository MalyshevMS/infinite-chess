#include "piece.hpp"
#include "../Board/board.hpp"

infChess::Piece::Piece(std::string texturePath, Color color) : sprite(texture), color(color) {
    if (!texture.loadFromFile(texturePath)) return;
    sprite.setTexture(texture, true);

    if (color == Color::Black) {
        sprite.setColor(sf::Color::Black);
    }
}

bool infChess::Piece::move(Board& board, sf::Vector2i offset) {
    sprite.move(sf::Vector2f(board.cell * offset));
    return true;
}

void infChess::Piece::drawOn(sf::RenderTarget &surface) {
    surface.draw(sprite);
}

sf::Vector2i infChess::Piece::getPosition() {
    return position;
}
