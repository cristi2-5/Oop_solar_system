#include "Planet.h"
#include "Satellite.h"
#include <iostream>
#include <string>

class Satellite;

Planet::Planet(std::string nume, double masa, double diametru, double x, double y, 
	std::string tip, bool atmosfera, int nrSateliti)
	: CorpCeresc(nume, masa, diametru, x, y),
	tip(tip), atmosfera(atmosfera), nrSateliti(nrSateliti) {
}
std::string Planet::getNume() {
	return nume;
}
void Planet::adaugaSatelit( Satellite s) {
	if (nrSateliti < MAX_SATELITI) {
		sateliti[nrSateliti] = s; 
		nrSateliti++;
	}
	else {
		std::cout << "Planeta " << nume << " nu poate avea mai mult de " << MAX_SATELITI << " sateliti!\n";
	}
}

void Planet::afisare() {
	std::cout << "Planeta: " << nume << " | Tip: " << tip << " | Atmosfera: "
		<< (atmosfera ? "Da" : "Nu") << " | Numar sateliti: " << nrSateliti  << std::endl;
	std::cout << "Sateliti care orbiteaza planeta " << nume << ":\n";
	if (nrSateliti == 0) {
		std::cout << "  Aceasta planeta nu are sateliti.\n";
	}
	else {
		for (int i = 0; i < nrSateliti; i++) {
			std::cout << "  ";
			sateliti[i].afisare();
		}
	}
}


