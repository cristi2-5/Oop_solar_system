#pragma once
#include "CorpCeresc.h"
class BlackHole : public CorpCeresc
{
private:
	double razaOrizontului; // Raza orizontului de eveniment

public:
	BlackHole(std::string nume, double masa, double diametru, double x, double y, double z, double razaOrizontului); // Constructor
	void afisare(); // Afiseaza informatiile despre gaura neagra
};

