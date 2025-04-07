#include "Rocket.h"
#include <iostream>
Rocket::Rocket() {
	if (!texture.loadFromFile("rocket.png")) {
		std::cerr << "Error loading texture" << std::endl;
	}
    sf::Sprite sprite(texture);
    sprite.setTexture(texture);
    sprite.setPosition({ 400.0f, 300.0f });
    sprite.setScale({ 0.1f, 0.1f });
    sprites.push_back(sprite);
    speed = 200.f; 
}

void Rocket::handleInput(float deltaTime) {
    sf::Vector2f movement(0.f, 0.f);

    bool up = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
    bool down = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S);
    bool left = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A);
    bool right = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);

    if (up)    movement.y -= 1.f;
    if (down)  movement.y += 1.f;
    if (left)  movement.x -= 1.f;
    if (right) movement.x += 1.f;

    
    
    if (up && left)        sprites[0].setRotation(sf::degrees(315.f)); 
    else if (up && right)  sprites[0].setRotation(sf::degrees(45.f));  
    else if (down && left) sprites[0].setRotation(sf::degrees(225.f)); 
    else if (down && right)sprites[0].setRotation(sf::degrees(135.f));
    else if (up)           sprites[0].setRotation(sf::degrees(0.f));   
    else if (down)         sprites[0].setRotation(sf::degrees(180.f)); 
    else if (left)         sprites[0].setRotation(sf::degrees(270.f)); 
    else if (right)        sprites[0].setRotation(sf::degrees(90.f));

    sprites[0].move(movement);
}

void Rocket::draw(sf::RenderWindow& window) {
    window.draw(sprites[0]);
}

sf::Vector2f Rocket::getPosition() const {
    return sprites[0].getPosition();
}

void Rocket::setPosition(const sf::Vector2f& pos) {
    sprites[0].setPosition(pos);
}