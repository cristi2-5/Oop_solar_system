#pragma once
#include <string>
#include "Star.h"
#include "Planet.h"
#include "SpaceObject.h"
#include "Satellite.h"
#include "TelluricPlanet.h"
#include "GazeousPlanet.h"
#include "Meteorite.h"
#include <vector>



class System
{
    private:
		std::vector<Meteorite> meteorites;
		std::vector<Planet*> planets;
		std::vector<TelluricPlanet*> telluricPlanets;
		std::vector<Star*> stars;
		std::vector<SpaceObject*> bodies;
		std::vector<Satellite*> satellites;
		float meteoriteSpawnTimer = 0.0f;
		float meteoriteSpawnInterval = 5.0f;
		
    public:
		System() {}; // Constructor    
		void addSun(Star* body);
		void addPlanet(Planet* body);
		void addSatellite(Satellite* body);
		sf::CircleShape createEntity(SpaceObject* body);
		sf::Color colorConvertor(std::string color);
		std::vector<sf::CircleShape> drawEntities();
		void updatePlanetRotation(Planet* planet,float step);
		void updateSatelliteRotation(Satellite* satellite, float step);
		void updateMeteorites(float dt, float screenWidth, float screenHeight);
		void drawMeteorites(sf::RenderWindow& window);
		~System() {};
};

