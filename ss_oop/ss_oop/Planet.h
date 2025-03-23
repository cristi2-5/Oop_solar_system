#pragma once
#include "CorpCeresc.h"
#include <string>   
class Planet : public CorpCeresc
{
private:
    std::string tip; // Tipul planetei (terestrã, gazoasã etc.)
    bool atmosfera; // Indicã dacã planeta are atmosferã
    int numarSatelliti; // Numãrul de sateli?i naturali

public:
    Planet(std::string nume, double masa, double diametru, double x, double y, double z,
        std::string tip, bool atmosfera, int numarSatelliti);
    std::string getNume();
    void afisare();
    friend class Satelit;
};

