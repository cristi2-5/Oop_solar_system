#include "Meteorite.h"

namespace Space {

    Meteorite::Meteorite(float spawnWidth, float spawnHeight)
        : SpaceObject("Meteorite", 0.001f, 20.0f, { 100.f, 100.f }, "gray") {

        float x = static_cast<float>(rand() % static_cast<int>(spawnWidth));
        float y = static_cast<float>(rand() % static_cast<int>(spawnHeight));
        setPosition({ x, y });

        float angle = static_cast<float>(rand() % 360) * 3.1415f / 180.0f;
        float speed = 250.f + rand() % 1000;
        velocity = { cos(angle) * speed, sin(angle) * speed };

    }

    void Meteorite::update(float dt) {
        sf::Vector2f pos = getPosition();
        pos += velocity * dt;
        setPosition(pos);
    }

    void Meteorite::draw(sf::RenderWindow& window) {
        sf::CircleShape shape(getDiameter());
        shape.setPosition(getPosition());
        shape.setFillColor(sf::Color(128, 128, 128));
        window.draw(shape);
    }

    void Meteorite::afisare() const {
        std::cout << "Meteoritul " << getName() << " are diametrul de " << getDiameter() << " km, culoarea " << getColor()
            << ", si se deplaseaza in directia (" << velocity.x << ", " << velocity.y << "). Se afla la pozitia ("
            << getPosition().x << ", " << getPosition().y << ")." << std::endl;
    }

}
