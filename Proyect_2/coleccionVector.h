#pragma once
#include "iterador.h"
#include <iostream>
#include "coleccion.h"
#include<sstream>
#include<vector>
using namespace std;
template<class T>
class coleccionVector : public coleccion<T>
{
private:
	vector<T>* v;
public:
	coleccionVector();
	void agregarObjeto(T&);
	bool eliminarObjeto(string);
	string toString();
	string mostrarObjeto(string );
	bool buscarObjeto(string);
	void ordenarObjetos();
	iterador<T>* getIterador();
	
};

template<class T>
inline coleccionVector<T>::coleccionVector()
{
	
}

template<class T>
inline void coleccionVector<T>::agregarObjeto(T& objeto )
{
	v->push_back(objeto);
}

template<class T>
inline bool coleccionVector<T>::eliminarObjeto(string id)
{
	for (int i = 0; i<=v->size(); i++) {
		if (v->at(i).getId() == id) {
			v->erase(v->begin()+i);
			return true;
		}
	}
	return false;
}

template<class T>
inline string coleccionVector<T>::toString()
{
	stringstream ss;
	for (int i = 0; i <= v->size(); i++) {
		ss << v->at(i).toString() << endl;
	}
	return ss.str();
}

template<class T>
inline string coleccionVector<T>::mostrarObjeto(string id)
{
	for (int i = 0; i <= v->size(); i++) {
		if(v->at(i).getId() == id)
			return v->at(i)->toString();
	}
	return "Objeto no encontrado";
}

template<class T>
inline bool coleccionVector<T>::buscarObjeto(string id)
{
	for (int i = 0; i <= v->size(); i++) {
		if(v->at(i).getId() == id) {
			return true;
		}
	}

	return false;
}

template<class T>
inline void coleccionVector<T>::ordenarObjetos()
{
	
	
}

template<class T>
inline iterador<T>* coleccionVector<T>::getIterador()
{
	return new iterador<T>(this->v);
}













