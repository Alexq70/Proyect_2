#pragma once
#ifndef COLECCION_H
#define COLECCION_H
#include <iostream>
#include "iterador.h"
using namespace std;
template <class T>
class coleccion
{
public:
	virtual void agregarObjeto(T*) = 0;
	virtual bool eliminarObjeto(T*) = 0;
	virtual string mostrarObjeto(T*) = 0;
	virtual bool buscarObjeto(T*) = 0;
	virtual string toString() = 0;
	virtual iterador<T>* getIterador()=0;

};
#endif // !COLECCION_H
