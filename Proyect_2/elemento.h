#pragma once
#include<iostream>
#include "coordenada.h"

using namespace std;
class elemento
{
private:
	

public:
	virtual string toString() = 0;
	virtual char getTipo() = 0; // Devuelve el tipo de elemento (agua, planta, criatura)
	virtual coordenada& getCoordenada() = 0; // Devuelve la coordenada del elemento
};
