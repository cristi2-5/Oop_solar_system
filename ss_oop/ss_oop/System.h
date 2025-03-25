#pragma once
#include <string>
#include "Stea.h"
#include "Planet.h"

#define MAX_PLANETE 20
#define MAX_STELE 20

class System
{
    private:
		std::string nume; // Numele sistemului
        Stea stea[MAX_STELE]; // Steaua central�
        Planet planete[MAX_PLANETE];// Lista de planete din sistem
		int NrPlanete,NrStele; // Numarul de planete din sistem
    public:
		System(std::string nume,int NrPlanete, int NrStele); // Constructor    

		void adaugaPlaneta(const Planet& p); // Adauga o planeta in sistem
		void adaugaStea(const Stea& s); // Adauga o stea in sistem
};

