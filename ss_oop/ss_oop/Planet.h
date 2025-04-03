#pragma once
#include "SpaceObject.h"
#include <string>   



class Planet : public SpaceObject
{
private:
    std::string type; // Tipul planetei (terestra, gazoasa etc.)
    bool atmosphere; // Indica daca planeta are atmosfera  
    float temperature;
public:
 
    Planet(std::string name, double mass, double diameter, sf::Vector2f position, std::string color,bool atmosphere, float temperature); // Constructor
    std::string getName(); // Getter pentru nume
    void afisare(); // Afiseaza informatiile despre planet
    float getTemperature() const;
};