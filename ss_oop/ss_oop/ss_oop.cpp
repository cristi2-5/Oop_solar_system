#include <iostream>
#include "CorpCeresc.h"
#include "Stea.h"
#include "Planet.h"
#include "Satellite.h"
#include "BlackHole.h"
#include "System.h"
int main()
{
	Stea soare("Soae", 1234, 123, 3123, 32132, 0, 123, 123, "spiralata");
	Planet p("Pamant", 123, 123, 123, 123, 123, "terestra", true, 0);
	Planet p2("Marte", 123, 123, 123, 123, 123, "terestra", true, 0);
	Satellite s("Luna", 123, 123, 123, 123, 123);
	Satellite s2("Phobos", 123, 123, 123, 123, 123);
	BlackHole b("Gaura Neagra", 123, 123, 123, 123, 123, 123);
	System sys("Sistem Solar", 2, 1);
	p.adaugaSatelit(s);
	p.adaugaSatelit(s2);
	sys.adaugaPlaneta(p);
	sys.adaugaPlaneta(p2);
	sys.adaugaStea(soare);
	sys.afisare();
	s.afisare();
	s.afiseazaNumePlaneta(p);
	return 0;
}

