#pragma once
#ifndef HERBIVORO_H
#define HERBIVORO_H
#include"criatura.h"
class herbivoro : public criatura{
public:
	herbivoro(); // constructor por defecto
	herbivoro(char tipo,string id , int energia, int edad, coordenada c);
	string getId();
	char getTipo();
	int getEnergia();
	int getEdad();
	coordenada getCoordenada();
	//---------------------
	void setTipo(char tipo);
	void setEnergia(int);
	void setEdad(int);
	void setCoordenada(coordenada);
	~herbivoro();
	string toString();
};

#endif // !HERBIVORO_H