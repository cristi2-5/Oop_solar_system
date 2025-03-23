#include "CorpCeresc.h"
#include <iostream>
CorpCeresc::CorpCeresc(std::string nume, double masa, double diametru, double x, double y, double z)
	: nume(nume), masa(masa), diametru(diametru), x(x), y(y), z(z) {
}
std::string CorpCeresc::GetNume() {
	return nume;
}
void CorpCeresc::afisare() {
	std::cout << "Corp ceresc: " << nume << " | Masa: " << masa << " | Diametru: "
		<< diametru << " | Pozitie: (" << x << ", " << y << ", " << z << ")" << std::endl;
}