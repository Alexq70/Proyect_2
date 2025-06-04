#pragma once
#include "iteradorVector.h"
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
	bool eliminarObjeto(T&);
	string toString();
	string mostrarObjeto(T& );
	bool buscarObjeto(T&);
	void ordenarObjetos();
	iteradorVector<T>* getIterador();
	
	
};

template<class T>
inline coleccionVector<T>::coleccionVector()
{
	v = new vector<T>();
}

template<class T>
inline void coleccionVector<T>::agregarObjeto(T& objeto )
{
	v->push_back(objeto);
}

template<class T>
inline bool coleccionVector<T>::eliminarObjeto(T& ob)  // aqui debe recibir un objeto que viene con el id a buscar y dato quemado en el resto
{
	for (int i = 0; i<=v->size(); i++) {
		if (v->at(i) == ob) { // 
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
	for (int i = 0; i < v->size(); i++) { //antes recorria un aposicion de mas
		ss << *v->at(i); // sobrecargado
	}
	return ss.str();
}


template<class T>
inline string coleccionVector<T>::mostrarObjeto(T& id) // aqui debe recibir un objeto que viene con el id a buscar y dato quemado en el resto, para la sobrecarga
{
	stringstream s;
	for (int i = 0; i < v->size(); i++) {
		if(v->at(i) == id)
			s<<*v->at(i);
	}
	if(!s) 
		s<<"Objeto no encontrado"<<endl;
	return s.str();
}

template<class T>
inline bool coleccionVector<T>::buscarObjeto(T& id) // aqui debe recibir un objeto que viene con el id a buscar y dato quemado en el resto
{
	for (int i = 0; i < v->size(); i++) {
		if(v->at(i) == id) {
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
inline iteradorVector<T>* coleccionVector<T>::getIterador()
{
   return new iteradorVector<T>(this->v); 
}

#endif // COLECCIONVECTOR_H











