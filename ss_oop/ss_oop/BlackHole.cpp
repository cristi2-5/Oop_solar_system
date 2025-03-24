#include "BlackHole.h"
#include <iostream>
BlackHole::BlackHole(std::string nume, double masa, double diametru, double x, double y,  double razaOrizontului)
    :CorpCeresc(nume, masa, diametru, x, y), razaOrizontului(razaOrizontului) {

}

void BlackHole::afisare()  {
    std::cout << "Gaura Neagra: " << nume << " | Masa: " << masa << " kg | Raza Orizontului: " << razaOrizontului << " km" << std::endl;
}
