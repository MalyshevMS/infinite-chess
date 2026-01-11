#include "boardSprite.hpp"

infChess::BoardSprite::BoardSprite(const int spriteSize, const int cellSize, const int cells, bool drawBorders) {
    texture.drawBoard(cellSize, cells, drawBorders);

    sprite = new sf::Sprite(texture.getTexture());
    sprite->setTextureRect(sf::IntRect({0, 0}, {spriteSize, spriteSize}));
    sprite->setOrigin({spriteSize / 2.f, spriteSize / 2.f});
    sprite->setPosition({0.f, 0.f});
}

void infChess::BoardSprite::drawOn(sf::RenderTarget &surface) {
    if (sprite) surface.draw(*sprite);
}
