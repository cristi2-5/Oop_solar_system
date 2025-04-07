#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>  
#include "SpaceObject.h"  
#include "Star.h"  
#include "Planet.h" 
#include "System.h"
#include "Satellite.h"
#include "Rocket.h"
int main()  
{  
   sf::Clock clock; 
   System system;
   Rocket rocket;
   Star* sun1 = new Star("Sun", 100, 100, {0.f,0.f},100,"Yellow");
   TelluricPlanet* planet1 = new TelluricPlanet("Earth", 100, 20, { 400.f,400.f }, "Blue",true,10,"telluric",sun1);
   GazeousPlanet* planet2 = new GazeousPlanet("Neptun", 100, 50, { 1000.f,1000.f }, "Red", true, 10,"gaseous",sun1);
   Satellite* satellite1 = new Satellite("Moon", 10, 5, { 500.f,500.f }, "Red",planet1);
 
   system.addSun(sun1);
   system.addPlanet(planet1);
   system.addPlanet(planet2);
   system.addSatellite(satellite1);
   sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML 3 - Graphics");
   sf::View view;
   view.setSize({ 1920, 1080 });
   view.setCenter({0,0 });
   view.zoom(0.5f);
   
   while (window.isOpen()) {
       sf::Time dt = clock.restart();
       float deltaTime = dt.asSeconds();
       while (auto event = window.pollEvent()) {
           
           if (event->is<sf::Event::Closed>())
               window.close();
           if (const auto* mouseWheelScrolled = event->getIf<sf::Event::MouseWheelScrolled>())
           {
               if (mouseWheelScrolled->wheel == sf::Mouse::Wheel::Vertical) {
                   float zoomFactor = (mouseWheelScrolled->delta > 0) ? 0.9f : 1.1f;
                   view.zoom(zoomFactor);
               }
           }

       }
       window.setView(view);
       view.setCenter(rocket.getPosition());
	   rocket.handleInput(deltaTime);
       system.updateMeteorites(deltaTime, 1920, 1080);
       system.updatePlanetRotation(planet1,0.1);
	   system.updatePlanetRotation(planet2, 0.5);
       system.updateSatelliteRotation(satellite1, 0.002);
       window.clear();
       for (sf::CircleShape entities : system.drawEntities())
           window.draw(entities);
       system.drawMeteorites(window);
	   rocket.draw(window);
	   window.setView(view);   
       window.display();
   }
   sun1->afisare();
   planet1->afisare();
   delete sun1;
   delete planet1;
   delete planet2;
   delete satellite1;
   return 0;  
}
