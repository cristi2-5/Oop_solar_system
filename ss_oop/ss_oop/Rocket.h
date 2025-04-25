#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Rocket {
private:
    sf::Texture m_texture; // textura pentru sprite-ul rachetei
    std::vector<sf::Sprite> m_sprites; // vector de sprite-uri 
    float m_speed; 

public:
    Rocket();

    void HandleInput(float delta_time); 
    void Draw(sf::RenderWindow& window); 

    sf::Vector2f GetPosition() const; 
    void SetPosition(const sf::Vector2f& pos); 
};
