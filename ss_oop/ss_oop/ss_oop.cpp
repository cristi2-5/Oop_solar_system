#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>  
#include "SpaceObject.h"  
#include "Star.h"  
#include "Planet.h" 
#include "System.h"

int main()  
{  
   System system;
   Star* sun1 = new Star("Sun", 100, 100, {0.f,0.f},100,"Yellow");
   Planet* planet1 = new Planet("Earth", 100, 20, { 400.f,400.f }, "Blue",true,10);
 
   system.addSun(sun1);
   system.addPlanet(planet1);

   sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML 3 - Graphics");
   sf::View view;
   view.setSize({ 1920, 1080 });
   view.setCenter({0,0 });
   view.zoom(0.5f);
   
   while (window.isOpen()) {
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
       system.updatePlanetRotation(0.1);
       window.clear();
       for (sf::CircleShape entities : system.drawEntities())
           window.draw(entities);
	   window.setView(view);   
       window.display();
   }

    delete sun1;
   return 0;  
}
