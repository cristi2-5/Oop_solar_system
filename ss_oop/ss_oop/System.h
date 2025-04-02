#pragma once
#include <string>
#include "Stea.h"
#include "Planet.h"
#include "CorpCeresc.h"
#include <vector>

#define MAX_PLANETE 20
#define MAX_STELE 20

class System
{
    private:
		std::vector<CorpCeresc*> corpuri;

		
    public:
		System() {}; // Constructor    
		void adaugaCorp(CorpCeresc* corp);
		sf::CircleShape createEntity(CorpCeresc* corp);
		sf::Color colorConvertor(std::string color);
		std::vector<sf::CircleShape> drawEntities();
		~System() {};
};

