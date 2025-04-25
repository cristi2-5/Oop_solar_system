// satellite.h
#pragma once

#include "space_object.h"
#include "planet.h"
#include "i_rotating_entity.h"

namespace Space {

    // Clasa care modeleaz� un satelit ce orbiteaz� o planet�
    class Satellite : public SpaceObject, public IRotatingEntity {
    private:
        Planet* m_parent_planet; // Referin?� c�tre planeta �n jurul c�reia orbiteaz�

        struct OrbitData {
            float radius;
            float angle;
        };

    public:
        Satellite(std::string name, float mass, float diameter, sf::Vector2f position,
            std::string color, Planet* parent_planet);

        Satellite(std::string name, sf::Vector2f position);

        void Afisare() const override; // Afi?eaz� date despre satelit ?i planeta pe care o orbiteaz�

        void UpdateRotation(float step) override; // Rote?te satelitul �n jurul planetei p�rinte
        sf::Vector2f GetRotationCenter() const override; // Returneaz� centrul de rota?ie (planeta)
        float GetRotationRadius() const override; // Returneaz� raza de rota?ie (distan?a fa?� de planet�)
    };

} // namespace Space
