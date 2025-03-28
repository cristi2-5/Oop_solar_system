#include "System.h"
#include <iostream>
class Stea;
class Planet;

System::System(std::string nume, int NrPlanete, int NrStele) : nume(nume), NrPlanete(0), NrStele(0) {
	if (NrPlanete > MAX_PLANETE) {
		std::cout << "Prea multe planete" << std::endl;
		return;
	}
	if (NrStele > MAX_STELE) {
		std::cout << "Prea multe stele" << std::endl;
		return;
	}
}

void System::adaugaPlaneta(const Planet& p) {
	if (NrPlanete == MAX_PLANETE) {
		std::cout << "Prea multe planete" << std::endl;
		return;
	}
	planete[NrPlanete++] = p;
}

void System::adaugaStea(const Stea& s) {
	if (NrStele == MAX_STELE) {
		std::cout << "Prea multe stele" << std::endl;
		return;
	}
	stea[NrStele++] = s;
}


