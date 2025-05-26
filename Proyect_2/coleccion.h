#pragma once
#include <iostream>
#include "iterador.h"
using namespace std;
template <class T>
class coleccion
{
public:
	virtual void agregarObjeto() = 0;
	virtual bool eliminarObjeto() = 0;
	virtual string mostrarObjeto() = 0;
	virtual bool buscarObjeto() = 0;
	virtual void ordenarObjetos() = 0;
	virtual T* getIterador()=0;

};

