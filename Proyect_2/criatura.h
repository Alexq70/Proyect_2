#pragma once
#include <iostream>
#include <sstream>
using  namespace std;
class criatura {
protected:
	string id;
	string tipo;
	int energia;
	int edad;
public:
	criatura(string, string, int, int);
	virtual ~criatura();
	//---------------------
	string getId();
	string getTipo();
	int getEnergia();
	int getEdad();
	//---------------------
	void setTipo(string tipo);
	void setEnergia(int);
	void setEdad(int);
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

