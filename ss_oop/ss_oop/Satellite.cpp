#include "Satellite.h"
#include "Planet.h"
#include "CorpCeresc.h"
#include <iostream>

class Planet;

Satellite::Satellite(std::string nume, double masa, double diametru,
	double x, double y) : CorpCeresc(nume, masa, diametru, x, y) {
}
void Satellite::afisare()  {
	std::cout << "Satelit: " << nume << " orbitea in jurul planetei "  << NumeOrbita << std::endl;
}
std::string Satellite::getNume() {
	return nume;
}
void Satellite::SetNumeOrbita(std::string nume) {
	NumeOrbita = nume;
}