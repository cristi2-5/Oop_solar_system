#pragma once
#include <string>
#include <SFML/System.hpp>
class CorpCeresc
{	
	protected:
	std::string nume; 
	double masa, diametru;
	sf::Vector2f position;
	std::string type = "uknown",color;
	public:
	CorpCeresc(std::string nume, float masa, float diametru, sf::Vector2f position,std::string color);
	virtual ~CorpCeresc(){};	
	double getDiameter() const { return diametru; }
	std::string getColor() { return color; }
	sf::Vector2f getPosition() { return position; }
	void setPosition(sf::Vector2f pos) { position = pos; }
	void setType(std::string type);
};

