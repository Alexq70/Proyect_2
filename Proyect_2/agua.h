#pragma once
#include "recurso.h"
class agua : public recurso {
public:
	agua();
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

