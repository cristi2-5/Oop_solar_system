#pragma once
#include <string>
#include <SFML/System.hpp>
class SpaceObject
{	
	private:
	std::string name; 
	double mass, diameter;
	sf::Vector2f position;
	std::string color;
	public:
	SpaceObject(std::string name, float mass, float diameter, sf::Vector2f position,std::string color);
	virtual ~SpaceObject(){};	
	double getDiameter() const;
	std::string getColor() const;
	sf::Vector2f getPosition() const;
	void setPosition(sf::Vector2f pos);
	std::string getName() const;
};

