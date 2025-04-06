#include "System.h"
#include <iostream>
#include <cmath>
class Star;
class Planet;
class Satellite;
class Meteorite;



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

}


std::vector<sf::CircleShape> System::drawEntities()
{   
	std::vector < sf::CircleShape> sprites;
	for (auto body : bodies) {
		sprites.push_back(createEntity(body));
	}
	return sprites;
}
void System::updatePlanetRotation(Planet* planet,float step)
{
	sf::Vector2f pos = planet->getPosition();

	
	sf::Vector2f SunPosition = planet->getParentStar()->getPosition();

	float dx = pos.x - SunPosition.x;
	float dy = pos.y - SunPosition.y;
	float distance = sqrt(dx * dx + dy * dy);

	if (distance == 0) return;

	float angle = atan2(dy, dx);
	angle += step / distance;

	float newX = SunPosition.x + distance * cos(angle);
	float newY = SunPosition.y + distance * sin(angle);

	planet->setPosition({ newX, newY });
}
void System::updateSatelliteRotation(Satellite* satellite, float step)
{
	Planet* planet = satellite->getParentPlanet();
	if (!planet) return; 

	static std::unordered_map<Satellite*, float> angles; 

	auto [Xp, Yp] = planet->getPosition(); 

	
	static std::unordered_map<Satellite*, float> distances;

	if (distances.find(satellite) == distances.end()) {
		
		auto [Xs, Ys] = satellite->getPosition();
		float dx = Xs - Xp;
		float dy = Ys - Yp;
		distances[satellite] = sqrt(dx * dx + dy * dy);
		angles[satellite] = atan2(dy, dx);
	}

	angles[satellite] += step;

	float radius = distances[satellite];
	float newX = Xp + radius * cos(angles[satellite]);
	float newY = Yp + radius * sin(angles[satellite]);

	satellite->setPosition({ newX, newY });
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




