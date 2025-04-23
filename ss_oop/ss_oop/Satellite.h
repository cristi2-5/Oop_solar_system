#pragma once
#include "Planet.h"

namespace Space {

    class Satellite : public SpaceObject, public IRotatingEntity {
    public:
        Satellite(std::string name, float mass, float diameter, sf::Vector2f position,
            std::string color, Planet* parentPlanet);

        Satellite(std::string name, sf::Vector2f position);

        void afisare() const override;
        void updateRotation(float step) override;
        sf::Vector2f getRotationCenter() const override;
        float getRotationRadius() const override;

    private:
        Planet* parentPlanet;
        struct OrbitData {
		float radius;
		float angle;
	    };
    };
} 


	


