#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>  
#include "CorpCeresc.h"  
#include "Stea.h"  
#include "Planet.h" 
#include "System.h"

int main()  
{  
   System sistem;
   Stea* soare2 = new Stea("Soae2", 100, 60, {0.f,0.f},100,"Red");
   Stea* soare3 = new Stea("Soae2", 100, 60, { 310.f, 420.f }, 100, "Blue");
   Stea* soare4 = new Stea("Soae2", 100, 60, { 110.f, 540.f }, 100, "Red");
   Planet* planeta1 = new Planet("caca", 100, 20, { 400.f,400.f }, "Red",true,10);
 
   sistem.adaugaSoare(soare2);
   sistem.adaugaSoare(soare3);
   sistem.adaugaSoare(soare4);
   sistem.adaugaPlaneta(planeta1);

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
       sistem.updatePlanetRotation(0.1);
       window.clear();
       for (sf::CircleShape gay : sistem.drawEntities())
           window.draw(gay);
	   window.setView(view);   
       window.display();
   }

    delete soare2;
   return 0;  
}
