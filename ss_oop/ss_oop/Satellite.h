#pragma once
#include "CorpCeresc.h"
#include <string>
#include <iostream>

class Planet;

class Satellite : public CorpCeresc
{
private:
	
public:
	Satellite(std::string nume, double masa, double diametru, double x, double y, double z); // Constructor
	Satellite()
		: CorpCeresc("Necunoscut", 0, 0, 0, 0, 0) {
	}; // Constructor implicit
	std::string getNume();	// Getter pentru nume
	void afisare();	// Afiseaza informatiile despre satelit
	void afiseazaNumePlaneta( Planet p) {
		std::cout << "Planeta este: " << p.getNume() << std::endl;
	}

	friend class Planet;
	friend class System;
};

