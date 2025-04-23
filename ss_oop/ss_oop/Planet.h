#pragma once
#include "SpaceObject.h"
#include "IRotatingEntity.h"
#include "Star.h"
#include <string>   

namespace Space {

    class Planet : public SpaceObject, public IRotatingEntity
    {
    private:
        std::string type; // Tipul planetei (telurica, gazoasa etc.)
        bool atmosphere; // Indica daca planeta are atmosfera  
        float temperature;
        static int planetCount; // numarul de planete
        Star* parentStar;
    public:

        Planet(std::string name, double mass, double diameter, sf::Vector2f position, std::string color, bool atmosphere, float temperature, std::string type, Star* parentStar); // Constructor
        void afisare() const override; // Afiseaza informatiile despre planet
        float getTemperature() const;
        void updateRotation(float step) override;
        sf::Vector2f getRotationCenter() const override;
        float getRotationRadius() const override;
        std::string getType() const; // Getter pentru tipul planetei
        Star* getParentStar() const;// Getter pentru steaua parinte
        double operator+(const Planet& other) const;
        bool getAtmosphere() const;
        friend std::ostream& operator<<(std::ostream& out, const Planet& p);
        Planet(std::string name, sf::Vector2f position);
    };
};