#pragma once
#include<iostream>
#include<sstream>
#include"coordenada.h"
using namespace std;
class elemento
{
private:
	string id;
	char tipo;
	coordenada posicion;
public:
	bool operator==(elemento& other);
	elemento(char tipo, string id, coordenada p);
	virtual string toString();
	string getId();
	char getTipo();
	coordenada getCoordenada();
};
ostream& operator <<(ostream& , elemento& );