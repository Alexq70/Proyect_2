#pragma once
#include <iostream>
#include <sstream>
#include "coordenada.h"
using  namespace std;
class criatura {
protected:
	string id;
	string tipo;
	int energia;
	int edad;
	coordenada posicion;
public:
	criatura(string, string, int, int, coordenada);
	virtual ~criatura();
	//---------------------
	string getId();
	string getTipo();
	int getEnergia();
	int getEdad();
	coordenada getCoordenada();
	//---------------------
	void setTipo(string tipo);
	void setEnergia(int);
	void setEdad(int);
	void setCoordenada(coordenada);
	//---------------------
	virtual string toString(); // no hice ninguno virtual ouro porque todos implementan lo mismo

	bool operator==(criatura& c) {
		return (this->id == c.id);
	}

	friend ostream& operator<<(ostream& os, criatura& c) {
		os << c.toString();
		return os;
	}
};

