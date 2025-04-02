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
		std::vector<Planet*> planete;
		std::vector<Stea*> stele;
		std::vector<CorpCeresc*> corpuri;
		std::vector<sf::Vector2f> closestSunPosition;
		
    public:
		System() {}; // Constructor    
		void adaugaSoare(Stea* corp);
		void adaugaPlaneta(Planet* corp);
		sf::CircleShape createEntity(CorpCeresc* corp);
		sf::Color colorConvertor(std::string color);
		std::vector<sf::CircleShape> drawEntities();
		void updatePlanetRotation(float step);
		sf::Vector2f FindClosestSunPosition(CorpCeresc* corp);
		~System() {};
};

