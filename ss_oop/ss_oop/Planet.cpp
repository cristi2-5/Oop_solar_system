#include "Planet.h"
#include <iostream>
#include <string>

namespace Space {

	Planet::Planet(std::string name, double mass, double diameter, sf::Vector2f position, std::string color, bool atmosphere, float temperature, std::string type, Star* parentStar) : SpaceObject(name, mass, diameter, position, color) {
		this->atmosphere = atmosphere;
		this->temperature = temperature;
		this->type = type;
		this->parentStar = parentStar;
		planetCount++;
	}

	Planet::Planet(std::string name, sf::Vector2f position)
		: SpaceObject(name, 1.0, 10.0, position, "Gray") {
		this->atmosphere = false;
		this->temperature = 0.0f;
		this->type = "generic";
		this->parentStar = nullptr;
		Planet::planetCount++;
	}

	int Planet::planetCount = 0;

	void Planet::afisare() const {
		std::cout << "Planeta: " << getName() << " | Tip: " << type << " | Atmosfera: "
			<< getAtmosphere();

	}
	bool Planet::getAtmosphere() const
	{
		return atmosphere;
	}
	float Planet::getTemperature() const
	{
		return temperature;
	}

	std::string Planet::getType() const
	{
		return type;
	}


	Star* Planet::getParentStar() const
	{
		return parentStar;
	}

	double Planet::operator+(const Planet& other) const {
		sf::Vector2f pos1 = this->getPosition();
		sf::Vector2f pos2 = other.getPosition();
		float dx = pos1.x - pos2.x;
		float dy = pos1.y - pos2.y;
		return sqrt(dx * dx + dy * dy);
	}

	std::ostream& operator<<(std::ostream& out, const Planet& p) {
		out << "Planeta \"" << p.getName() << "\" este de tip " << p.getType()
			<< ", are un diametru de " << p.getDiameter() << " km"
			<< ", o temperatura de " << p.getTemperature() << "C"
			<< ", culoarea \"" << p.getColor() << "\""
			<< ", si atmosfera " << (p.atmosphere ? "prezenta" : "absenta")
			<< ". Se afla la pozitia (" << p.getPosition().x << ", " << p.getPosition().y << ")";
		return out;
	}

	void Planet::updateRotation(float step) {
		if (!parentStar) return;

		sf::Vector2f pos = getPosition();
		sf::Vector2f center = parentStar->getPosition();

		float dx = pos.x - center.x;
		float dy = pos.y - center.y;
		float distance = std::sqrt(dx * dx + dy * dy);

		if (distance == 0) return;

		float angle = std::atan2(dy, dx) + step / distance;
		float newX = center.x + distance * std::cos(angle);
		float newY = center.y + distance * std::sin(angle);

		setPosition({ newX, newY });
	}

	sf::Vector2f Planet::getRotationCenter() const {
		return parentStar ? parentStar->getPosition() : sf::Vector2f(0.f, 0.f);
	}

	float Planet::getRotationRadius() const {
		if (!parentStar) return 0.f;
		sf::Vector2f diff = getPosition() - parentStar->getPosition();
		return std::sqrt(diff.x * diff.x + diff.y * diff.y);
	}

}