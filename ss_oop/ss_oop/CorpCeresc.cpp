#include "CorpCeresc.h"
#include <iostream>
CorpCeresc::CorpCeresc(std::string nume, float masa, float diametru, sf::Vector2f position,std::string color) {
	this->nume=nume;
	this->masa = masa;
	this->diametru = diametru;
	this->position = position;
	this->color = color;
	
}
void CorpCeresc::setType(std::string pe)
{
	type = pe;
}
