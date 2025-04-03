#include "Star.h"
#include <iostream>

Star::Star(std::string name, float mass, float diameter, sf::Vector2f position, float temperature, std::string color):SpaceObject(name,mass,diameter,position,color){
    this->temperature = temperature;
}

float Star::getTemperature() const
{
    return temperature;
}


void Star::afisare()  {
    std::cout << "Stea: " << name << " | Tip: "  << " | Temp: "
        << temperature << "K" << std::endl;
}
