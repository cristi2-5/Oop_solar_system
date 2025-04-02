#pragma once
#include "CorpCeresc.h"
#include <string>   
#define MAX_SATELITI 20



class Planet : public CorpCeresc
{
private:
    std::string tip; // Tipul planetei (terestra, gazoasa etc.)
    bool atmosfera; // Indica daca planeta are atmosfera
    int nrSateliti;  
public:
 
    Planet(std::string nume, double masa, double diametru, sf::Vector2f position, std::string color,bool atmosfera, int numarSatelliti); // Constructor
  
    std::string getNume(); // Getter pentru nume
    void afisare(); // Afiseaza informatiile despre planet
};