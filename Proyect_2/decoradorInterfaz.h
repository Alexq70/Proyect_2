#pragma once
#include "interfazAbstracta.h"

class decoradorInterfaz : public interfazAbstracta
{
protected:
	interfazAbstracta* interfaz;
public:
	void cambiarModoMatriz(string,string){}

	decoradorInterfaz(interfazAbstracta* inter) {
		interfaz = inter;
	}
};

