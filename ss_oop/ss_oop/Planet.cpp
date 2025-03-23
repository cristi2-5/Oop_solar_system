#include "Planet.h"
#include <iostream>

Planet::Planet(std::string nume, double masa, double diametru, double x, double y, double z,
	std::string tip, bool atmosfera, int numarSatelliti)
	: CorpCeresc(nume, masa, diametru, x, y, z),
	tip(tip), atmosfera(atmosfera), numarSatelliti(numarSatelliti) {
}
std::string Planet::getNume() {
	return nume;
}
void Planet::afisare() {
	std::cout << "Planeta: " << nume << " | Tip: " << tip << " | Atmosfera: "
		<< (atmosfera ? "Da" : "Nu") << " | Numar sateliti: " << numarSatelliti << std::endl;
}
