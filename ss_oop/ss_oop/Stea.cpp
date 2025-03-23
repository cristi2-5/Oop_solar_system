#include "Stea.h"
#include <iostream>

Stea::Stea(std::string nume, double masa, double diametru, double x, double y, double z,
    double temperatura, double luminozitate, std::string tipSpectral)
    : CorpCeresc(nume, masa, diametru, x, y, z),
    temperatura(temperatura), luminozitate(luminozitate), tipSpectral(tipSpectral) {
}


void Stea::afisare()  {
    std::cout << "Stea: " << nume << " | Tip: " << tipSpectral << " | Temp: "
        << temperatura << "K | Luminozitate: " << luminozitate << std::endl;
}