#pragma once
#include <iostream>
#include <sstream>
#include "coordenada.h"
using namespace std;

class recurso {
protected:
	string id;
	string tipo;
	coordenada posicion; // no se usa en este caso, pero es parte de la clase base
public:
	recurso(string,string,coordenada);
	virtual ~recurso();
	//---------------------
	string getId();
	string getTipo();
	coordenada getCoordenada();
	//---------------------
	void setTipo(string tipo);
	void setCoordenada(coordenada pos);
	//---------------------
	virtual string toString(); // no hice ninguno virtual puro porque todos implementan lo mismo

	bool operator==(recurso& otro) {
		return (this->id == otro.id);
	}

	friend ostream& operator<<(ostream& os, recurso& r) {
		os << r.toString();
		return os;
	}

};

