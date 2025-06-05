#pragma once
#include "recurso.h"
#include "coordenada.h"
class carne : public recurso{
private:
	char tipo = 'K';
	string id;
	coordenada posicion;
public:
	bool operator==(carne&);
	carne(char, string, coordenada);
	//---------------------
	string getId();
	char getTipo();
	coordenada& getCoordenada();
	//---------------------
	void setTipo(char tipo);
	void setCoordenada(coordenada pos);
	//---------------------
	~carne();
	string toString();
};
ostream& operator<<(ostream&, carne&);

