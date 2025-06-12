#pragma once
#ifndef MATRIZ_H
#define MATRIZ_H
#include "iteradorVector.h"
#include "observerVector.h"
#include "coleccionVector.h"
#include "coordenada.h"
#include "windows.h"
#include "elemento.h"
#include <iostream>
#include <sstream>
#include <random>
using namespace std;
class matriz: public observerVector{
private:
	iteradorVector<elemento>* iterador;
	coleccionVector<elemento>* col;
	elemento* m[15][15];
public:
	matriz(coleccionVector<elemento>*);
	void actualizar();
	bool insertarElemneto(elemento* e, int x, int y);
	bool eliminarElemento(int x, int y);
	elemento* verificarCoordenada(coordenada );
	string mostrarMatriz();
	void updateCreacion();
	void updateEliminacion();
	coordenada coordenadaDisponibleM(coordenada c); // verifica si una coordenada esta disponible
	coordenada coordenadaRandom(); // genera una coordenada random

};
#endif 

