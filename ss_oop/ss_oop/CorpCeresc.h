#pragma once
#include <string>
class CorpCeresc
{	
	protected:
	std::string nume; 
	double masa, diametru, x, y; 
	public:
	CorpCeresc(std::string nume, double masa, double diametru, double x, double y);
	~CorpCeresc(){};	
};

