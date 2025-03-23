#pragma once
#include "CorpCeresc.h"
#include <string>
#include <iostream>

class Planet;

class Satellite : public CorpCeresc
{
private:
	std::string NumeOrbita;
public:
	Satellite(std::string nume, double masa, double diametru, double x, double y, double z); // Constructor
	Satellite()
		: CorpCeresc("Necunoscut", 0, 0, 0, 0, 0) {
	}; // Constructor implicit
	std::string getNume();	// Getter pentru nume
	void afisare();	// Afiseaza informatiile despre sateliti
	void SetNumeOrbita(std::string nume);
	friend class Planet;
	friend class System;
};

