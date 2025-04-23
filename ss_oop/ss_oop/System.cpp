#include "System.h"
#include "IRotatingEntity.h"
#include <iostream>
#include <cmath>
#include <unordered_map>
#include <cstdlib>

using namespace Space;

namespace Simulation {

	void System::addSun(Star* body)
	{
		stars.push_back(body);
		bodies.push_back(body);
	}

	void System::addPlanet(Planet* body)
	{
		planets.push_back(body);
		bodies.push_back(body);
	}

	void System::addSatellite(Satellite* body)
	{
		satellites.push_back(body);
		bodies.push_back(body);
	}

	sf::CircleShape System::createEntity(SpaceObject* body)
	{
		sf::CircleShape sprite(body->getDiameter());
		sprite.setFillColor(colorConvertor(body->getColor()));
		sprite.setPosition(body->getPosition());
		sprite.setOrigin(sprite.getGeometricCenter());
		return sprite;
	}

	sf::Color System::colorConvertor(std::string color) {
		if (color == "Red")
			return sf::Color::Red;
		if (color == "Blue")
			return sf::Color::Blue;
		if (color == "Green")
			return sf::Color::Green;
		if (color == "Yellow")
			return sf::Color::Yellow;
		if (color == "White")
			return sf::Color::White;
		return sf::Color::Black;
	}

	std::vector<sf::CircleShape> System::drawEntities()
	{
		std::vector<sf::CircleShape> sprites;
		for (auto body : bodies) {
			sprites.push_back(createEntity(body));
		}
		return sprites;
	}

	void System::rotateEntity(IRotatingEntity* entity, float step) {
		if (entity) entity->updateRotation(step);
	}

	void System::printOrbitData(IRotatingEntity* entity) {
		if (!entity) return;
		std::cout << "Obiect cu centrul de rotatie la (" << entity->getRotationCenter().x << ", " << entity->getRotationCenter().y
			<< ") si raza orbitala de " << entity->getRotationRadius() << " unitati." << std::endl;
	}

	void System::updateMeteorites(float dt, float screenWidth, float screenHeight) {
		meteoriteSpawnTimer -= dt;
		if (meteoriteSpawnTimer <= 0.0f) {
			meteorites.emplace_back(screenWidth, screenHeight);
			meteoriteSpawnTimer = meteoriteSpawnInterval;
		}

		for (int i = 0; i < meteorites.size(); i++) {
			meteorites[i].update(dt);
		}
	}

	void System::drawMeteorites(sf::RenderWindow& window) {
		for (auto& m : meteorites) {
			m.draw(window);
		}
	}

	void System::printObjects() const {
		for (auto body : bodies) {
			body->afisare(); 
		}
	}

} 
