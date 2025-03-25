#pragma once
#include <string>
class CorpCeresc
{	
	protected:
	std::string nume; 
	double masa, diametru, x, y; 
	public:
	CorpCeresc(std::string nume, float masa, float diametru, float x, float y);
	~CorpCeresc(){};	
};

