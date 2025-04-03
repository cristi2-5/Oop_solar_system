#pragma once
#include <string>
#include "Star.h"
#include "Planet.h"
#include "SpaceObject.h"
#include "Satellite.h"
#include <vector>



class System
{
    private:
		std::vector<Planet*> planets;
		std::vector<Star*> stars;
		std::vector<SpaceObject*> bodies;
		std::vector<sf::Vector2f> closestSunPosition;
		std::vector<Satellite*> satellites;
		
    public:
		System() {}; // Constructor    
		void addSun(Star* body);
		void addPlanet(Planet* body);
		void addSatellite(Satellite* body);;
		sf::CircleShape createEntity(SpaceObject* body);
		sf::Color colorConvertor(std::string color);
		std::vector<sf::CircleShape> drawEntities();
		void updatePlanetRotation(float step);
		void updateSatelliteRotation(Satellite* satellite, float step);
		sf::Vector2f FindClosestSunPosition(SpaceObject* body);
		~System() {};
};

