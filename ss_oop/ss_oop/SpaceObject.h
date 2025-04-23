#pragma once
#include <string>
#include <SFML/System.hpp>
namespace Space {
	class SpaceObject
	{
	private:
		std::string name;
		double mass, diameter;
		sf::Vector2f position;
		std::string color;
	public:
		SpaceObject(std::string name, float mass, float diameter, sf::Vector2f position, std::string color);
		virtual void afisare() const = 0;
		virtual void update(float dt) {}
		virtual ~SpaceObject() = default;
		double getDiameter() const;
		std::string getColor() const;
		sf::Vector2f getPosition() const;
		void setPosition(sf::Vector2f pos);
		std::string getName() const;
	};
}

