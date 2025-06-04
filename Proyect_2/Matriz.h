#pragma once
#ifndef MATRIZ_H
#define MATRIZ_H
#include "iteradorVector.h"
#include "coleccionVector.h"
#include "coordenada.h"
#include "elemento.h"
#include <iostream>
#include <sstream>
using namespace std;
class matriz {
private:
	iteradorVector<elemento*>* iterador;
	elemento* m[10][15];
public:
	matriz();
	matriz(iteradorVector<elemento*>*);
	bool insertarElemneto(elemento* e, int x, int y);
	bool eliminarElemento(int x, int y);
	string mostrarMatriz();
};
#endif 

