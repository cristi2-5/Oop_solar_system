#include "Planet.h"
#include <iostream>
#include <string>

Planet::Planet(std::string nume, double masa, double diametru, sf::Vector2f position,std::string color, bool atmosfera, int nrSateliti) : CorpCeresc(nume, masa, diametru, position,color){
this->atmosfera = atmosfera;
this->nrSateliti = nrSateliti;
}
std::string Planet::getNume() {
	return nume;
}


void Planet::afisare() {
	std::cout << "Planeta: " << nume << " | Tip: " << tip << " | Atmosfera: "
		<< (atmosfera ? "Da" : "Nu") << " | Numar sateliti: " << nrSateliti  << std::endl;
	
}


