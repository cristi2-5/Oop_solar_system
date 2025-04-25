#include "planet.h"
#include <iostream>
#include <string>
#include <cmath>

namespace Space {

    Planet::Planet(std::string name, double mass, double diameter, sf::Vector2f position, std::string color,
        bool atmosphere, float temperature, std::string type, Star* parent_star)
        : SpaceObject(name, mass, diameter, position, color), m_atmosphere(atmosphere), m_temperature(temperature),
        m_type(type), m_parent_star(parent_star) {
        planet_count++;
    }

    Planet::Planet(std::string name, sf::Vector2f position)
        : SpaceObject(name, 1.0, 10.0, position, "Gray"), m_atmosphere(false), m_temperature(0.0f),
        m_type("generic"), m_parent_star(nullptr) {
        planet_count++;
    }

    int Planet::planet_count = 0;

    void Planet::Afisare() const {
        std::cout << "Planeta: " << GetName() << " | Tip: " << m_type << " | Atmosfera: " << m_atmosphere;
    }

    bool Planet::GetAtmosphere() const {
        return m_atmosphere;
    }

    float Planet::GetTemperature() const {
        return m_temperature;
    }

    std::string Planet::GetType() const {
        return m_type;
    }

    Star* Planet::GetParentStar() const {
        return m_parent_star;
    }

    // supraincarcare +
    double Planet::operator+(const Planet& other) const {
        sf::Vector2f pos1 = GetPosition();
        sf::Vector2f pos2 = other.GetPosition();
        float dx = pos1.x - pos2.x;
        float dy = pos1.y - pos2.y;
        return std::sqrt(dx * dx + dy * dy);
    }

    // supraincarcare <<
    std::ostream& operator<<(std::ostream& out, const Planet& p) {
        out << "Planeta \"" << p.GetName() << "\" este de tip " << p.GetType()
            << ", are un diametru de " << p.GetDiameter() << " km"
            << ", o temperatura de " << p.GetTemperature() << "C"
            << ", culoarea \"" << p.GetColor() << "\""
            << ", si atmosfera " << (p.m_atmosphere ? "prezenta" : "absenta")
            << ". Se afla la pozitia (" << p.GetPosition().x << ", " << p.GetPosition().y << ")";
        return out;
    }

    // functie de rotatie in jurul stelei parinte
    void Planet::UpdateRotation(float step) {
        if (!m_parent_star) return;

        sf::Vector2f pos = GetPosition();
        sf::Vector2f center = m_parent_star->GetPosition();

        float dx = pos.x - center.x;
        float dy = pos.y - center.y;
        float distance = std::sqrt(dx * dx + dy * dy);
        if (distance == 0) return;

        float angle = std::atan2(dy, dx) + step / distance;
        float new_x = center.x + distance * std::cos(angle);
        float new_y = center.y + distance * std::sin(angle);

        SetPosition({ new_x, new_y });
    }

    sf::Vector2f Planet::GetRotationCenter() const {
        return m_parent_star ? m_parent_star->GetPosition() : sf::Vector2f(0.f, 0.f);
    }

    float Planet::GetRotationRadius() const {
        if (!m_parent_star) return 0.f;
        sf::Vector2f diff = GetPosition() - m_parent_star->GetPosition();
        return std::sqrt(diff.x * diff.x + diff.y * diff.y);
    }

} 
