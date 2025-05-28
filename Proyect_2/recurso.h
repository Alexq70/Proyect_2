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
	virtual string toString(); // no hice ninguno virtual puro porque todos implementan lo mismo

	bool operator==(recurso& otro) {
		return (this->id == otro.id && this->tipo == otro.tipo);
	}

	friend ostream& operator<<(ostream& os, recurso& r) {
		os << r.toString();
		return os;
	}

};

