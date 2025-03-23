#include <iostream>  
#include "CorpCeresc.h"  
#include "Stea.h"  
#include "Planet.h"  
#include "Satellite.h"  
#include "BlackHole.h"  
#include "System.h"  
int main()  
{  
   Satellite* s2 = new Satellite("Phobos", 123, 123, 123, 123, 123);  
   Satellite* s = new Satellite("Luna", 123, 123, 123, 123, 123);  
   Stea* soare = new Stea("Soae", 1234, 123, 3123, 32132, 0, 123, 123, "spiralata");  
   Planet* p = new Planet("Pamant", 123, 123, 123, 123, 123, "terestra", true, 0);  
   Planet* p2 = new Planet("Marte", 123, 123, 123, 123, 123, "terestra", true, 0);  
   BlackHole* b = new BlackHole("Gaura Neagra", 123, 123, 123, 123, 123, 123);  
   System* sys = new System("Sistem Solar", 2, 1);  
   s->SetNumeOrbita(p->getNume());  
   s2->SetNumeOrbita(p->getNume());  
   p->adaugaSatelit(*s);  
   p->adaugaSatelit(*s2);  
   sys->adaugaPlaneta(*p);  
   sys->adaugaPlaneta(*p2);  
   sys->adaugaStea(*soare);  
   sys->afisare();  
   delete s2;  
   delete s;  
   delete soare;  
   delete p;  
   delete p2;  
   delete b;  
   delete sys;  
   return 0;  
}
