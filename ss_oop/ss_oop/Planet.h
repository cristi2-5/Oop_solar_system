#pragma once
#include "CorpCeresc.h"
#include "Satellite.h" 
#include <string>   
#define MAX_SATELITI 20



class Planet : public CorpCeresc
{
private:
    std::string tip; // Tipul planetei (terestra, gazoasa etc.)
    bool atmosfera; // Indica daca planeta are atmosfera
    Satellite sateliti[MAX_SATELITI]; // Array fix pentru sateliti
    int nrSateliti; 
public:
    Planet()
        : CorpCeresc("Pământ", 2000, 2000, 0, 0, 0),
        tip("Terestră"), atmosfera(true), nrSateliti(0) {
    }; // Constructor implicit
    Planet(std::string nume, double masa, double diametru, double x, double y, double z,
        std::string tip, bool atmosfera, int numarSatelliti); // Constructor
    void adaugaSatelit(Satellite s);
    std::string getNume(); // Getter pentru nume
    void afisare(); // Afiseaza informatiile despre planeta
	 // Adauga un satelit in jurul planetei
    friend class System;
};