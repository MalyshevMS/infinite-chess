#pragma once

#include "../Game/drawable.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace infChess {
    class Piece : public Drawable {
    protected:
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Vector2i position;
        class Board* pBoard;
        class Board& board = *pBoard;
    public:
        Piece(class Board& board, std::string texturePath);


        virtual bool move(sf::Vector2i offset);
        virtual void drawOn(sf::RenderTarget& surface) override;
        
        virtual sf::Vector2i getPosition();
    };
}