// main.cpp
#include <SFML/Graphics.hpp>
#include <iostream>

#include "simulation_manager.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "Solar System Simulation");
    sf::View view({ 0.f, 0.f }, { 1920.f, 1080.f });
    view.zoom(0.5f);

    sf::Clock clock;
    SimulationManager simulation;
    simulation.Init();

    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();

            simulation.HandleInput(*event, view);
        }

        float dt = clock.restart().asSeconds();
        view.setCenter(simulation.GetRocket().GetPosition());
        window.setView(view);

        simulation.Update(dt);

        window.clear();
        simulation.Draw(window);
        window.display();
    }

    return 0;
}
