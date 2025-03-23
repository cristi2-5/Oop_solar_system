#pragma once
#include "CorpCeresc.h"

class Stea : public CorpCeresc
{
private:
    double temperatura, luminozitate;
    std::string tipSpectral;

public:
    Stea(std::string nume, double masa, double diametru, double x, double y, double z,
        double temperatura, double luminozitate, std::string tipSpectral);

    void afisare();

};

