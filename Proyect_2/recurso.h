#pragma once
#include "Utiles.h"
#include <iostream>
#include <sstream>
using namespace std;

class recurso {
protected:
	string id;
	string tipo;
public:
	recurso(string,string);
	virtual ~recurso();
	//---------------------
	string getId();
	string getTipo();
	//---------------------
	void setTipo(string tipo);
	//---------------------
	virtual string toString(); // no hice ninguno virtual ouro porque todos implementan lo mismo

};

