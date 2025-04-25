// simulation_manager.cpp
#include "simulation_manager.h"
#include "system.h"
#include "telluric_planet.h"
#include "gazeous_planet.h"
#include <SFML/Graphics.hpp>

#include <iostream>

using namespace Space;
using namespace Simulation;

void SimulationManager::Init() {
    // Star
    Star* sun = new Star("Sun", 1000.f, 300.f, { 0.f, 0.f }, 5778.f, "Yellow");
    m_system.AddSun(sun);

    // Telluric Planets
    TelluricPlanet* mercury = new TelluricPlanet("Mercury", 100.f, 80.f, { 1200.f, 0.f }, "Gray", false, 167.f, "telluric", sun);
    TelluricPlanet* venus = new TelluricPlanet("Venus", 100.f, 100.f, { 1800.f, 0.f }, "Orange", true, 464.f, "telluric", sun);
    TelluricPlanet* earth = new TelluricPlanet("Earth", 100.f, 120.f, { 2700.f, 0.f }, "Blue", true, 15.f, "telluric", sun);
    TelluricPlanet* mars = new TelluricPlanet("Mars", 100.f, 100.f, { 3600.f, 0.f }, "Red", true, -60.f, "telluric", sun);

    m_system.AddPlanet(mercury);
    m_system.AddPlanet(venus);
    m_system.AddPlanet(earth);
    m_system.AddPlanet(mars);

    // Gaseous Planets
    GazeousPlanet* jupiter = new GazeousPlanet("Jupiter", 100.f, 180.f, { 4800.f, 0.f }, "Orange", true, -110.f, "gaseous", sun);
    GazeousPlanet* saturn = new GazeousPlanet("Saturn", 100.f, 170.f, { 5700.f, 0.f }, "LightYellow", true, -140.f, "gaseous", sun);
    GazeousPlanet* uranus = new GazeousPlanet("Uranus", 100.f, 160.f, { 6600.f, 0.f }, "Cyan", true, -195.f, "gaseous", sun);
    GazeousPlanet* neptune = new GazeousPlanet("Neptune", 100.f, 160.f, { 7500.f, 0.f }, "Blue", true, -200.f, "gaseous", sun);

    m_system.AddPlanet(jupiter);
    m_system.AddPlanet(saturn);
    m_system.AddPlanet(uranus);
    m_system.AddPlanet(neptune);

    // Satellites
    Satellite* moon = new Satellite("Moon", 0.5f, 40.f, { 3000.f, 0.f }, "White", earth);
    Satellite* phobos = new Satellite("Phobos", 0.1f, 36.f, { 3900.f, 150.f }, "Gray", mars);
    Satellite* deimos = new Satellite("Deimos", 0.08f, 30.f, { 3900.f, -150.f }, "Gray", mars);
    Satellite* europa = new Satellite("Europa", 0.9f, 40.f, { 4950.f, 190.f }, "White", jupiter);
    Satellite* ganymede = new Satellite("Ganymede", 1.5f, 50.f, { 4950.f, -190.f }, "White", jupiter);
    Satellite* titan = new Satellite("Titan", 1.4f, 44.f, { 5850.f, 225.f }, "Orange", saturn);
    Satellite* oberon = new Satellite("Oberon", 0.7f, 40.f, { 6750.f, 225.f }, "Red", uranus);
    Satellite* triton = new Satellite("Triton", 0.9f, 40.f, { 7650.f, 225.f }, "Green", neptune);

    m_system.AddSatellite(moon);
    m_system.AddSatellite(phobos);
    m_system.AddSatellite(deimos);
    m_system.AddSatellite(europa);
    m_system.AddSatellite(ganymede);
    m_system.AddSatellite(titan);
    m_system.AddSatellite(oberon);
    m_system.AddSatellite(triton);

}

void SimulationManager::HandleInput(const sf::Event& event, sf::View& view) {

    if (const auto* scroll = event.getIf<sf::Event::MouseWheelScrolled>()) {
        if (scroll->wheel == sf::Mouse::Wheel::Vertical) {
            float zoom_factor = (scroll->delta > 0) ? 0.9f : 1.1f;
            view.zoom(zoom_factor);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B) && !m_black_hole) {
        m_black_hole = new BlackHole(m_rocket.GetPosition(), 1e8f);
        m_white_flash_timer = 0.5f;
    }
}

void SimulationManager::Update(float delta_time) {
    m_rocket.HandleInput(delta_time);

    if (m_black_hole)
        m_black_hole->Attract(m_system.GetBodies(), delta_time);

    m_system.UpdateMeteorites(delta_time, 1920, 1080);

    m_system.RotateByName("Mercury", 0.5f);
    m_system.RotateByName("Venus", 0.4f);
    m_system.RotateByName("Earth", 0.35f);
    m_system.RotateByName("Mars", 0.3f);
    m_system.RotateByName("Jupiter", 0.25f);
    m_system.RotateByName("Saturn", 0.225f);
    m_system.RotateByName("Uranus", 0.2f);
    m_system.RotateByName("Neptune", 0.175f);


    // rotatii sateliti
    m_system.RotateByName("Moon", 0.002f);
    m_system.RotateByName("Phobos", 0.0024f);
    m_system.RotateByName("Deimos", 0.0022f);
    m_system.RotateByName("Europa", 0.002f);
    m_system.RotateByName("Ganymede", 0.0019f);
    m_system.RotateByName("Titan", 0.0018f);
    m_system.RotateByName("Oberon", 0.0016f);
    m_system.RotateByName("Triton", 0.0016f);

}

void SimulationManager::Draw(sf::RenderWindow& window) {
    for (sf::CircleShape entity : m_system.DrawEntities())
        window.draw(entity);

    if (m_black_hole)
        m_black_hole->Draw(window);

    m_system.DrawMeteorites(window);
    m_rocket.Draw(window);
}

