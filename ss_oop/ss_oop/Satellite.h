// satellite.h
#pragma once

#include "space_object.h"
#include "planet.h"
#include "i_rotating_entity.h"

namespace Space {

    // Clasa care modeleazã un satelit ce orbiteazã o planetã
    class Satellite : public SpaceObject, public IRotatingEntity {
    private:
        Planet* m_parent_planet; // Referin?ã cãtre planeta în jurul cãreia orbiteazã

        struct OrbitData {
            float radius;
            float angle;
        };

    public:
        Satellite(std::string name, float mass, float diameter, sf::Vector2f position,
            std::string color, Planet* parent_planet);

        Satellite(std::string name, sf::Vector2f position);

        void Afisare() const override; // Afi?eazã date despre satelit ?i planeta pe care o orbiteazã

        void UpdateRotation(float step) override; // Rote?te satelitul în jurul planetei pãrinte
        sf::Vector2f GetRotationCenter() const override; // Returneazã centrul de rota?ie (planeta)
        float GetRotationRadius() const override; // Returneazã raza de rota?ie (distan?a fa?ã de planetã)
    };

} // namespace Space
