#pragma once
#include "recurso.h"
class agua : public recurso {
private:
	char tipo = 'A';
	string id;
	coordenada posicion;
public:
	bool operator==(agua&);
	elemento* clonar() const;
	agua(char, string, coordenada);
	//---------------------
	string getId();
	char getTipo();
	coordenada getCoordenada();
	//---------------------
	void setTipo(char tipo);
	void setCoordenada(coordenada pos);
	//---------------------
	~agua();
	string toString();
};
ostream& operator<<(ostream&, agua&);

