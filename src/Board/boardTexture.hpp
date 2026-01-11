#pragma once

#include <SFML/Graphics.hpp>
#include <string>

namespace infChess {
    class BoardTexture {
    private:
        const sf::Color lightColor = {240, 217, 181};
        const sf::Color darkColor  = {181, 136, 99 };
        sf::RenderTexture texture;
        sf::Texture baseTexture;
    public:
        BoardTexture() {};
        void drawBoard(int cellSize = 10, int cells = 8, bool drawBorders = false);
        const sf::Texture& getTexture();
    };    
}
