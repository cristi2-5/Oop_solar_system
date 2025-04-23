#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Star.h"
#include "Planet.h"
#include "Satellite.h"
#include "TelluricPlanet.h"
#include "GazeousPlanet.h"
#include "Meteorite.h"
#include "IRotatingEntity.h"

namespace Simulation {

	class System {
	private:
		struct OrbitData {
			float radius;
			float angle;
		};

		std::vector<Space::Meteorite> meteorites;
		std::vector<Space::Planet*> planets;
		std::vector<Space::TelluricPlanet*> telluricPlanets;
		std::vector<Space::Star*> stars;
		std::vector<Space::SpaceObject*> bodies;
		std::vector<Space::Satellite*> satellites;
		float meteoriteSpawnTimer = 0.0f;
		float meteoriteSpawnInterval = 5.0f;

	public:
		System() = default;
		~System() = default;

		void addSun(Space::Star* body);
		void addPlanet(Space::Planet* body);
		void addSatellite(Space::Satellite* body);

		sf::CircleShape createEntity(Space::SpaceObject* body);
		sf::Color colorConvertor(std::string color);
		std::vector<sf::CircleShape> drawEntities();

		void rotateEntity(IRotatingEntity* entity, float step);
		void printOrbitData(IRotatingEntity* entity);

		void updateMeteorites(float dt, float screenWidth, float screenHeight);
		void drawMeteorites(sf::RenderWindow& window);

		void printObjects() const;

	};

} 