#pragma once

#include "../Game/drawable.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace infChess {
    class Piece : public Drawable {
    public:
        enum class Color {
            White, Black
        };
    protected:
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Vector2i position;
        Color color;
    public:
        Piece(std::string texturePath, Color color);

        virtual bool move(class Board& board, sf::Vector2i offset);
        virtual void drawOn(sf::RenderTarget& surface) override;
        
        virtual sf::Vector2i getPosition();
    };
}