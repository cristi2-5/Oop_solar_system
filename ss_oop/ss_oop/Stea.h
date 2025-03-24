#pragma once
#include "CorpCeresc.h"

class Stea : public CorpCeresc 
{
private:
	double temperatura, luminozitate; // Temperatura si luminozitatea stelei
	std::string tipSpectral; // Tipul spectral al stelei

public:
	Stea()
		: CorpCeresc("Soare", 2000, 2000, 0, 0),
		temperatura(5778), luminozitate(1.0), tipSpectral("G2V") {
	}; // Constructor implicit
    Stea(std::string nume, double masa, double diametru, double x, double y,
		double temperatura, double luminozitate, std::string tipSpectral); // Constructor

	void afisare(); // Afiseaza informatiile despre stea
	friend class System;
};

