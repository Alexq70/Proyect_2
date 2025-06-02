#pragma once
#include <iostream>
#include "iterador.h"
using namespace std;
template <class T>
class coleccion
{
public:
	virtual void agregarObjeto(T&) = 0;
	virtual bool eliminarObjeto(T&) = 0;
	virtual string mostrarObjeto(T&) = 0;
	virtual bool buscarObjeto(T&) = 0;
	virtual void ordenarObjetos() = 0;
	virtual string toString() = 0;
	//virtual T* getIterador()=0;

};

