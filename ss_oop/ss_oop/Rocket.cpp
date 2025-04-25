#include "rocket.h"
#include <iostream>

Rocket::Rocket() {
    if (!m_texture.loadFromFile("rocket.png")) {
        std::cerr << "Error loading texture" << std::endl;
    }

    sf::Sprite sprite(m_texture);
    sprite.setTexture(m_texture);
    sprite.setPosition({ 400.0f, 300.0f });
    sprite.setScale({ 0.1f, 0.1f });

    m_sprites.push_back(sprite);
    m_speed = 200.f;
}

void Rocket::HandleInput(float delta_time) {
    sf::Vector2f movement(0.f, 0.f);

    bool up = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
    bool down = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S);
    bool left = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A);
    bool right = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);

    if (up)    movement.y -= 1.f;
    if (down)  movement.y += 1.f;
    if (left)  movement.x -= 1.f;
    if (right) movement.x += 1.f;

    if (up && left)        m_sprites[0].setRotation(sf::degrees(315.f));
    else if (up && right)  m_sprites[0].setRotation(sf::degrees(45.f));
    else if (down && left) m_sprites[0].setRotation(sf::degrees(225.f));
    else if (down && right)m_sprites[0].setRotation(sf::degrees(135.f));
    else if (up)           m_sprites[0].setRotation(sf::degrees(0.f));
    else if (down)         m_sprites[0].setRotation(sf::degrees(180.f));
    else if (left)         m_sprites[0].setRotation(sf::degrees(270.f));
    else if (right)        m_sprites[0].setRotation(sf::degrees(90.f));

    m_sprites[0].move(movement * m_speed * delta_time);
}

void Rocket::Draw(sf::RenderWindow& window) {
    window.draw(m_sprites[0]);
}

sf::Vector2f Rocket::GetPosition() const {
    return m_sprites[0].getPosition();
}

void Rocket::SetPosition(const sf::Vector2f& pos) {
    m_sprites[0].setPosition(pos);
}
