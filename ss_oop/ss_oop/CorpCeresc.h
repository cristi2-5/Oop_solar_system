#pragma once
#include <string>
class CorpCeresc
{	
	protected:
	std::string nume;
	double masa, diametru, x, y, z;
	public:
	CorpCeresc(std::string nume, double masa, double diametru, double x, double y, double z);
	~CorpCeresc(){};
	std::string GetNume();
	void afisare();
};

