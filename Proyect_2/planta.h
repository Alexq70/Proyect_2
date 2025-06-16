#pragma once
#include "recurso.h"
class planta : public recurso {
private:
	char tipo = 'P';;
	string id;
	coordenada posicion;
public:
	bool operator==(planta&);
	elemento* clonar() const;
	planta(char,string, coordenada);
	//---------------------
	string getId();
	char getTipo();
	coordenada getCoordenada();
	//---------------------
	void setTipo(char tipo);
	void setId(string);
	void setCoordenada(coordenada pos);
	//---------------------
	~planta();
	string toString();
};
ostream& operator<<(ostream&, planta&);
