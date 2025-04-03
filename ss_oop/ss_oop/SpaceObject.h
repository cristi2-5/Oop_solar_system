#pragma once
#include <string>
#include <SFML/System.hpp>
class SpaceObject
{	
	protected:
	std::string name; 
	double mass, diameter;
	sf::Vector2f position;
	std::string type = "uknown",color;
	public:
	SpaceObject(std::string name, float mass, float diameter, sf::Vector2f position,std::string color);
	virtual ~SpaceObject(){};	
	double getDiameter() const;
	std::string getColor();
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f pos);
	void setType(std::string type);
};

