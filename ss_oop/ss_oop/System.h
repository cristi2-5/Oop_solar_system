#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "star.h"
#include "planet.h"
#include "satellite.h"
#include "meteorite.h"
#include "space_object.h"

using namespace Space;

namespace Simulation {

    // clasa System gestioneaza toate entitatile spatiale si logica de simulare
    class System {
    private:
        std::unordered_map<std::string, SpaceObject*> m_object_map;

        std::vector<SpaceObject*> m_bodies; // toate entitatile spatiale
        std::vector<Star*> m_stars;
        std::vector<Planet*> m_planets;
        std::vector<Satellite*> m_satellites;
        std::vector<Meteorite> m_meteorites; // meteoriti activi

        float m_meteorite_spawn_timer = 0.f;
        float m_meteorite_spawn_interval = 3.5f;

        sf::Color ColorConvertor(std::string color); 
        sf::CircleShape CreateEntity(SpaceObject* body); // creeaza forma vizuala pt. un obiect

    public:
        void AddSun(Star* body);
        void AddPlanet(Planet* body);
        void AddSatellite(Satellite* body);
        std::vector<SpaceObject*>& GetBodies();
        SpaceObject* GetObject(const std::string& name);


        std::vector<sf::CircleShape> DrawEntities();
        void DrawMeteorites(sf::RenderWindow& window);

        void RotateEntity(IRotatingEntity* entity, float step); // roteste o entitate
        void PrintOrbitData(IRotatingEntity* entity); 

        void UpdateMeteorites(float delta_time, float screen_width, float screen_height); // update meteoriti
        void RotateByName(const std::string& name, float step);
        void PrintObjects() const; 
    };
}
