#include "meteorite.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

namespace Space {

    Meteorite::Meteorite(float spawn_width, float spawn_height)
        : SpaceObject("Meteorite", 0.001f, 20.0f, { 100.f, 100.f }, "gray") {

        // initializeaza pozitia aleatorie pe ecran
        float x = static_cast<float>(rand() % static_cast<int>(spawn_width));
        float y = static_cast<float>(rand() % static_cast<int>(spawn_height));
        SetPosition({ x, y });

        // directie si viteza aleatoare pentru deplasare
        float angle = static_cast<float>(rand() % 360) * 3.1415f / 180.0f;
        float speed = 250.f + rand() % 1000;
        m_velocity = { std::cos(angle) * speed, std::sin(angle) * speed };
    }

    void Meteorite::Update(float delta_time) {
        sf::Vector2f pos = GetPosition();
        pos += m_velocity * delta_time;
        SetPosition(pos);
    }

    void Meteorite::Draw(sf::RenderWindow& window) {
        sf::CircleShape shape(GetDiameter());
        shape.setPosition(GetPosition());
        shape.setFillColor(sf::Color(128, 128, 128));
        window.draw(shape);
    }

    void Meteorite::Afisare() const {
        std::cout << "Meteoritul " << GetName() << " are diametrul de " << GetDiameter() << " km, culoarea " << GetColor()
            << ", si se deplaseaza in directia (" << m_velocity.x << ", " << m_velocity.y << "). Se afla la pozitia ("
            << GetPosition().x << ", " << GetPosition().y << ")." << std::endl;
    }

} 
