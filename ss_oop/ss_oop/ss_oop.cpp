#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>  
#include "CorpCeresc.h"  
#include "Stea.h"  
#include "Planet.h"  
#include "Satellite.h"  
#include "BlackHole.h"  
#include "System.h"

int main()  
{  
 
   Stea* soare2 = new Stea("Soae2", 1234.0f, 150.0f,160.0f,320.0f,100,"Yellow"); 
   sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML 3 - Graphics");
   Stea* soare1 = new Stea("Soae2", 1234.0f, 300.0f, 320.0f, 160.0f, 100, "Yellow");
   sf::View view;
   view.setSize({ 1920, 1080 });
   view.setCenter({ 960, 540 });
   view.zoom(0.5f);
   // zoom the view relatively to its current size (apply a factor 0.5, so its final size is 600x400)
   
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
        window.clear();
       
	   window.setView(view);   
       soare2->drawme(window);
	   soare1->drawme(window);
       window.display();
   }

    delete soare2;
   return 0;  
}
