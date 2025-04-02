#include "Stea.h"
#include <iostream>

Stea::Stea(std::string nume, float masa, float diametru, sf::Vector2f position, float temperatura, std::string color):CorpCeresc(nume,masa,diametru,position,color){
    this->temperatura = temperatura;
}


void Stea::afisare()  {
    std::cout << "Stea: " << nume << " | Tip: "  << " | Temp: "
        << temperatura << "K" << std::endl;
}
