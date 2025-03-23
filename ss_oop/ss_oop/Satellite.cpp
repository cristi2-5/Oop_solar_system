#include "Satellite.h"
#include "Planet.h"
#include <iostream>

class Planet;

Satellite::Satellite(std::string nume, double masa, double diametru,
	double x, double y, double z) : CorpCeresc(nume, masa, diametru, x, y, z) {
}
void Satellite::afisare()  {
	std::cout << "Satelit: " << nume << " orbiteaza in jurul planetei "  << std::endl;
}
std::string Satellite::getNume() {
	return nume;
}