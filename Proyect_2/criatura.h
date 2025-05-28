#pragma once
#include <iostream>
#include <sstream>
using  namespace std;
class criatura {
protected:
	string id;
	string tipo;
public:
	criatura(string, string);
	virtual ~criatura();
	//---------------------
	string getId();
	string getTipo();
	//---------------------
	void setTipo(string tipo);
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

