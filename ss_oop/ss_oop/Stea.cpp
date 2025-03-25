#include "Stea.h"
#include <iostream>

Stea::Stea(std::string nume, float masa, float diametru, float x, float y,
    float temperatura,std::string culoare)
    : CorpCeresc(nume, masa, diametru, x, y),temperatura(temperatura),culoare(culoare){
    forma.setRadius(diametru/2);
    forma.setFillColor(sf::Color::Yellow);
	forma.setPosition({ x, y });
    forma.setOrigin(sf::Vector2f(forma.getRadius(), forma.getRadius()));
}


void Stea::afisare()  {
    std::cout << "Stea: " << nume << " | Tip: "  << " | Temp: "
        << temperatura << "K" << std::endl;
}
void Stea::drawme(sf::RenderWindow& window) {
    window.draw(forma);
}