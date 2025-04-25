#pragma once

#include <SFML/System/Vector2.hpp>
#include <string>

namespace Space {

    // clasa de baza pentru orice obiect spatial (planete, stele, sateliti, meteoriti etc.)
    class SpaceObject {
    private:
        int m_durability;
        std::string m_name; 
        float m_mass;       
        float m_diameter;   
        sf::Vector2f m_position; 
        std::string m_color;
        void InitDurability();

    public:
        SpaceObject(std::string name, float mass, float diameter, sf::Vector2f position, std::string color);

        std::string GetName() const;
        double GetDiameter() const;
        sf::Vector2f GetPosition() const;
        void SetPosition(sf::Vector2f position);
        std::string GetColor() const;

        int GetDurability() const;
        void ReduceDurability();
        bool IsDestroyed() const;

        virtual void Afisare() const = 0; // functie pur virtuala pentru afisare custom
    };

} 
