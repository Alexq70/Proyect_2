#pragma once
#include "recurso.h"
class planta : public recurso {
private:
	char tipo = 'P';;
	string id;
	coordenada posicion;
public:
	planta();
	planta(char,string, coordenada);
	//---------------------
	string getId();
	char getTipo();
	coordenada getCoordenada();
	//---------------------
	void setTipo(char tipo);
	void setCoordenada(coordenada pos);
	//---------------------
	~planta();
	string toString();
};
ostream& operator<<(ostream&, planta&);
