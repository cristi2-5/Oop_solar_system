#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class Rocket {
private:
    sf::RectangleShape shape;
    sf::Texture texture;
	std::vector<sf::Sprite> sprites;
    float speed;

public:
    Rocket();
    void handleInput(float deltaTime);
    sf::Vector2f getPosition() const;

    void setPosition(const sf::Vector2f& pos);
    void draw(sf::RenderWindow& window);
};

