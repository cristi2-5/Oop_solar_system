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
   Satellite* s2 = new Satellite("Phobos", 123, 123, 123, 123);  
   Satellite* s = new Satellite("Luna", 123, 123, 123, 123);  
   Stea* soare = new Stea("Soae", 1234, 123, 3123, 32132, 0, 123, "spiralata");
   Stea* soare2 = new Stea("Soae2", 1234, 123, 3123, 32132, 0, 123, "spiralata");
   Planet* p = new Planet("Pamant", 123, 123, 123, 123, "terestra", true, 0);  
   Planet* p2 = new Planet("Marte", 123, 123, 123, 123, "terestra", true, 0);  
   BlackHole* b = new BlackHole("Gaura Neagra", 123, 123, 123, 123, 123);  
   System* sys = new System("Sistem Solar", 2, 2);  
   s->SetNumeOrbita(p->getNume());  
   s2->SetNumeOrbita(p->getNume());  
   p->adaugaSatelit(*s);  
   p->adaugaSatelit(*s2);  
   sys->adaugaPlaneta(*p);  
   sys->adaugaPlaneta(*p2);  
   sys->adaugaStea(*soare);
   sys->adaugaStea(*soare2);
   sys->afisare();  
   delete s2;  
   delete s;  
   delete soare;  
   delete p;  
   delete p2;  
   delete b;  
   delete sys;
   sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML 3 - Graphics");

   sf::CircleShape shape(100.f);
   shape.setFillColor(sf::Color::Green);

   while (window.isOpen()) {
       while (auto event = window.pollEvent()) {
           if (event->is<sf::Event::Closed>())
               window.close();
       }

       window.clear();
       window.draw(shape);
       window.display();
   }


   return 0;  
}
