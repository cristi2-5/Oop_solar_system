#pragma once

#include "space_object.h"
#include "star.h"
#include "i_rotating_entity.h"

namespace Space {

    class Planet : public SpaceObject, public IRotatingEntity {
    private:
        bool m_atmosphere;
        float m_temperature;
        std::string m_type;
        Star* m_parent_star;
        static int planet_count; 
    
    public:
        Planet(std::string name, double mass, double diameter, sf::Vector2f position,
            std::string color, bool atmosphere, float temperature, std::string type, Star* parent_star);

        Planet(std::string name, sf::Vector2f position);

        void Afisare() const override; 

        bool GetAtmosphere() const;
        float GetTemperature() const;
        std::string GetType() const;
        Star* GetParentStar() const;

        double operator+(const Planet& other) const; 

        void UpdateRotation(float step) override; 
        sf::Vector2f GetRotationCenter() const override;
        float GetRotationRadius() const override;

        friend std::ostream& operator<<(std::ostream& out, const Planet& p);

    
    };

} 


