#include "boardTexture.hpp"
#include <algorithm>

void infChess::BoardTexture::drawBoard(int cellSize, int cells, bool drawBorders) {
    if (cellSize <= 0) cellSize = 10;
    if (cells <= 0) cells = 8;

    const int border = 10;
    const int boardSize = cells * cellSize;
    const int texSize = boardSize;
    
    texture = sf::RenderTexture({(uint)texSize, (uint)texSize});
    texture.clear(sf::Color::Transparent);
    
    
    
    sf::RectangleShape rect({(float)cellSize, (float)cellSize});
    for (int y = 0; y < cells; ++y) {
        for (int x = 0; x < cells; ++x) {
            const bool isLight = ((x + y) % 2 == 0);
            rect.setFillColor(isLight ? lightColor : darkColor);
            rect.setPosition({(float)x * cellSize, (float)y * cellSize});
            texture.draw(rect);
        }
    }

    if (drawBorders) {
        sf::RectangleShape frame({(float)boardSize - border, (float)boardSize - border});
        frame.setFillColor(sf::Color::Transparent);
        frame.setOutlineThickness((float)border);
        frame.setOutlineColor(sf::Color::Black);
        texture.draw(frame);
    }
    
    texture.display();

    sf::Image img = texture.getTexture().copyToImage();
    if (!baseTexture.loadFromImage(img)) return;
    baseTexture.setRepeated(true);
}

const sf::Texture& infChess::BoardTexture::getTexture() {
    return baseTexture;
}