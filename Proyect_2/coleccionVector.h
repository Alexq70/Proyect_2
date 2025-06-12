#pragma once
#ifndef COLECCIONVECTOR_H
#define COLECCIONVECTOR_H

#include "iteradorVector.h"
#include <iostream>
#include "coleccion.h"
#include<sstream>
#include<vector>
#include "carnivoro.h"
#include "herbivoro.h"
#include "omnivoro.h"
#include "planta.h"
#include "agua.h"
using namespace std;
class observerVector; 
template<class T>
class coleccionVector : public coleccion<T>
{
private:
	vector<T*>* v;
	observerVector* observer;
public:
	coleccionVector();
	void agregarObjeto(T*);
	bool eliminarObjeto(T*);
	string toString();
	string mostrarObjeto(T* );
	bool buscarObjeto(T*);
	elemento* buscarObjetoId(string);
	iteradorVector<T>* getIterador(); // NO FUNCA
	void agregarObserver(observerVector* o);
	void eliminarObserver(observerVector* o);
	void notifyCreacion();
	void notifyEliminacion();
	int getTamano();
	elemento* getObjeto(int);
	void limpiarMatriz();
};

template<class T>
inline void coleccionVector<T>::agregarObserver(observerVector* o)
{
	this->observer = o;
}

template<class T>
inline void coleccionVector<T>::eliminarObserver(observerVector* o)
{
	this->observer = nullptr;
}

template<class T>
inline void coleccionVector<T>::notifyCreacion()
{
	observer->updateCreacion(); // notificar al observer de la creacion del elemento
}

template<class T>
inline void coleccionVector<T>::notifyEliminacion()
{
	observer->updateEliminacion(); // notificar al observer de la eliminacion del elemento
}

template<class T>
inline coleccionVector<T>::coleccionVector()
{
	v = new vector<T*>(); // inicializar el vector
}

template<class T>
inline void coleccionVector<T>::agregarObjeto(T* objeto )
{
	v->push_back(objeto);
	this->notifyCreacion();
}

template<class T>
inline bool coleccionVector<T>::eliminarObjeto(T* objeto)  // aqui debe recibir un objeto que viene con el id a buscar y dato quemado en el resto
{
	for (int i = 0; i<v->size(); i++) {
		if (v->at(i) == objeto) { // 
			v->erase(v->begin()+i);
			this->notifyEliminacion();
			return true;
		}
	}
	return false;
}

template<class T>
inline string coleccionVector<T>::toString()
{
	stringstream ss;
	for (int i = 0; i < v->size(); i++) { 
		ss << v->at(i)->toString() << endl; // se muestra el objeto
	}
	return ss.str();
}

template<class T>
inline string coleccionVector<T>::mostrarObjeto(T* ob)
{
	stringstream s;
	for (int i = 0; i < v->size(); i++) {
		if (v->at(i) == ob) { // se compara el objeto con el que se busca
			s << v->at(i)->toString() << endl; // se muestra el objeto
			return s.str();
		}
	}
}


template<class T>
inline bool coleccionVector<T>::buscarObjeto(T* id) // aqui debe recibir un objeto que viene con el id a buscar y dato quemado en el resto
{
	for (int i = 0; i < v->size(); i++) {
		if(v->at(i) == id) {
			return true;
		}
	}
	return false;
}

template<class T>
inline elemento* coleccionVector<T>::buscarObjetoId(string id)
{
	for (int i = 0; i < v->size(); i++) {
		if (v->at(i)->getId() == id) {
			return v->at(i);
		}
	}
	return nullptr;
}

template<class T>
inline iteradorVector<T>* coleccionVector<T>::getIterador()
{
	return new iteradorVector<T>(this->v);
}
template <class T>
inline int coleccionVector<T>::getTamano() {
	return v->size()-1;
}
template<class T>
inline elemento* coleccionVector<T>::getObjeto(int i)
{
	if (v->at(i) == nullptr) {
		return nullptr;
	}
	return v->at(i);
}

template<class T>
inline void coleccionVector<T>::limpiarMatriz()
{
	v->clear();
	this->notifyEliminacion();
}


#endif // !COLECCIONVECTOR_H












