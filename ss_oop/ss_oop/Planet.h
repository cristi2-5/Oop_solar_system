#pragma once
#include "SpaceObject.h"
#include "Star.h"
#include <string>   



class Planet : public SpaceObject
{
private:
    std::string type; // Tipul planetei (telurica, gazoasa etc.)
    bool atmosphere; // Indica daca planeta are atmosfera  
    float temperature;
    Star* parentStar; 
public:
 
    Planet(std::string name, double mass, double diameter, sf::Vector2f position, std::string color,bool atmosphere, float temperature,std::string type,Star* parentStar); // Constructor
    void afisare(); // Afiseaza informatiile despre planet
    float getTemperature() const;
    std::string getType() const; // Getter pentru tipul planetei
    Star* getParentStar() const;// Getter pentru steaua parinte
};