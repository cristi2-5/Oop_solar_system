#include <iostream>
#include "CorpCeresc.h"
#include "Stea.h"
#include "Planet.h"
int main()
{
	Stea pamant("Soare", 1234, 123, 3123, 32132, 0, 123, 123, "spiralata");
	pamant.afisare();
	Planet p("Pamant", 123, 123, 123, 123, 123, "terestra", true, 1);
	p.afisare();
}

//hjuguyguy