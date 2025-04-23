#include "Satellite.h"
#include <iostream>
#include <cmath>
#include <unordered_map>

namespace Space {

    Satellite::Satellite(std::string name, float mass, float diameter, sf::Vector2f position, std::string color, Planet* parentPlanet)
        : SpaceObject(name, mass, diameter, position, color), parentPlanet(parentPlanet) {
    }

    Satellite::Satellite(std::string name, sf::Vector2f position)
        : SpaceObject(name, 0.5f, 3.0f, position, "White"), parentPlanet(nullptr) {
    }

    void Satellite::afisare() const {
        std::cout << "Satelitul " << getName() << " are un diametru de " << getDiameter() << " km, culoarea " << getColor()
            << ", si se afla la pozitia (" << getPosition().x << ", " << getPosition().y << ")";
        if (parentPlanet)
            std::cout << ", orbitand planeta " << parentPlanet->getName();
        std::cout << "." << std::endl;
    }

    void Satellite::updateRotation(float step) {
        if (!parentPlanet) return;

        static std::unordered_map<const Satellite*, OrbitData> orbitDataMap;

        sf::Vector2f planetPos = parentPlanet->getPosition();
        sf::Vector2f satPos = getPosition();

        if (orbitDataMap.find(this) == orbitDataMap.end()) {
            float dx = satPos.x - planetPos.x;
            float dy = satPos.y - planetPos.y;
            float radius = std::sqrt(dx * dx + dy * dy);
            float angle = std::atan2(dy, dx);
            orbitDataMap[this] = { radius, angle };
        }

        orbitDataMap[this].angle += step;

        float r = orbitDataMap[this].radius;
        float angle = orbitDataMap[this].angle;

        float newX = planetPos.x + r * std::cos(angle);
        float newY = planetPos.y + r * std::sin(angle);

        setPosition({ newX, newY });
    }

    sf::Vector2f Satellite::getRotationCenter() const {
        return parentPlanet ? parentPlanet->getPosition() : sf::Vector2f(0.f, 0.f);
    }

    float Satellite::getRotationRadius() const {
        if (!parentPlanet) return 0.f;
        sf::Vector2f diff = getPosition() - parentPlanet->getPosition();
        return std::sqrt(diff.x * diff.x + diff.y * diff.y);
    }
}