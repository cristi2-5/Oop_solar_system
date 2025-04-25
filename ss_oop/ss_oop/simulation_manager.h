#pragma once

#include "system.h"
#include "rocket.h"
#include "black_hole.h"

class SimulationManager {
private:
    Simulation::System m_system;
    Rocket m_rocket;
    Space::BlackHole* m_black_hole = nullptr;
    float m_white_flash_timer = 0.f;

public:
    void Init();
    void HandleInput(const sf::Event& event, sf::View& view);
    void Update(float delta_time);
    void Draw(sf::RenderWindow& window);

    Simulation::System& GetSystem() { return m_system; }
    Rocket& GetRocket() { return m_rocket; }
};

