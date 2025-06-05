#pragma once
#ifndef OBSERVERVECTOR_H
#define OBSERVERVECTOR_H
#include "coleccionVector.h"
#include "iteradorVector.h"
#include "elemento.h"
template<class T>
class coleccionVector;
class observerVector
{
private:
	coleccionVector<elemento*>* v; // Colección de observadores
public:
	virtual void updateCreacion(elemento& e)=0;
	virtual void updateEliminacion(elemento& e)=0;
};
#endif 
