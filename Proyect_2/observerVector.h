#pragma once
#include <iostream>
#include "elemento.h"
using namespace std;
template <class T>
class coleccionVector;
class observerVector{
private:
	coleccionVector<elemento>* coleccion;
public:
	observerVector(coleccionVector<elemento>* c);
	virtual void updateCreacion() = 0;
	virtual void updateEliminacion() = 0;
};

