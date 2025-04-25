#include "satellite.h"
#include <iostream>
#include <cmath>
#include <unordered_map>

namespace Space {

    Satellite::Satellite(std::string name, float mass, float diameter, sf::Vector2f position,
        std::string color, Planet* parent_planet)
        : SpaceObject(name, mass, diameter, position, color), m_parent_planet(parent_planet) {
    }

    Satellite::Satellite(std::string name, sf::Vector2f position)
        : SpaceObject(name, 0.5f, 3.0f, position, "White"), m_parent_planet(nullptr) {
    }

    void Satellite::Afisare() const {
        std::cout << "Satelitul " << GetName() << " are un diametru de " << GetDiameter() << " km, culoarea "
            << GetColor() << ", si se afla la pozitia (" << GetPosition().x << ", " << GetPosition().y << ")";
        if (m_parent_planet)
            std::cout << ", orbitand planeta " << m_parent_planet->GetName();
        std::cout << "." << std::endl;
    }

    void Satellite::UpdateRotation(float step) {
        if (!m_parent_planet) return;

        // stocarea datelor orbitei pentru fiecare obiect 
        static std::unordered_map<const Satellite*, OrbitData> orbit_data_map;

        sf::Vector2f planet_pos = m_parent_planet->GetPosition();
        sf::Vector2f sat_pos = GetPosition();

        // inițializam datele orbitei daca nu exista
        if (orbit_data_map.find(this) == orbit_data_map.end()) {
            float dx = sat_pos.x - planet_pos.x;
            float dy = sat_pos.y - planet_pos.y;
            float radius = std::sqrt(dx * dx + dy * dy);
            float angle = std::atan2(dy, dx);
            orbit_data_map[this] = { radius, angle };
        }

        orbit_data_map[this].angle += step;

        float r = orbit_data_map[this].radius;
        float angle = orbit_data_map[this].angle;

        float new_x = planet_pos.x + r * std::cos(angle);
        float new_y = planet_pos.y + r * std::sin(angle);

        SetPosition({ new_x, new_y });
    }

    sf::Vector2f Satellite::GetRotationCenter() const {
        return m_parent_planet ? m_parent_planet->GetPosition() : sf::Vector2f(0.f, 0.f);
    }

    float Satellite::GetRotationRadius() const {
        if (!m_parent_planet) return 0.f;
        sf::Vector2f diff = GetPosition() - m_parent_planet->GetPosition();
        return std::sqrt(diff.x * diff.x + diff.y * diff.y);
    }

} 
