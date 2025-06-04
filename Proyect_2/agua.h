#pragma once
#include "recurso.h"
class agua : public recurso {
private:
	char tipo = 'A';
	string id;
	coordenada posicion;
public:
	agua(string,coordenada);
	~agua();
	string toString();
};
ostream& operator<<(ostream&, agua&);

