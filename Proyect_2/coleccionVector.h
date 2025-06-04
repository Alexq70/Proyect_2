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
	string mostrarObjeto(string id);
	bool buscarObjeto(T&);
	void ordenarObjetos();
	iteradorVector<T>* getIterador(); // NO FUNCA
	
};

template<class T>
inline coleccionVector<T>::coleccionVector()
{
	v = new vector<T>(); // inicializar el vector
}

template<class T>
inline void coleccionVector<T>::agregarObjeto(T& objeto )
{
	v->push_back(objeto);
}

template<class T>
inline bool coleccionVector<T>::eliminarObjeto(T& id)  // aqui debe recibir un objeto que viene con el id a buscar y dato quemado en el resto
{
	for (int i = 0; i<=v->size(); i++) {
		if (v->at(i) == id) { // 
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
	char tipo = 'n';
	agua* a = nullptr; // inicializar punteros a null
	planta* p = nullptr; // inicializar punteros a null
	carnivoro* c = nullptr; // inicializar punteros a null
	herbivoro* h = nullptr; // inicializar punteros a null
	omnivoro* o = nullptr; // inicializar punteros a null
	for (int i = 0; i < v->size(); i++) { //antes recorria un aposicion de mas
		if (dynamic_cast<carnivoro*>(v->at(i))) // si es un carnivoro
		{
			tipo = 'C';
			 c = new carnivoro(*dynamic_cast<carnivoro*>(v->at(i))); // si es un carnivoro, se crea un objeto de tipo carnivoro
		}
		else if (dynamic_cast<herbivoro*>(v->at(i))) // si es un herbivoro
		{
			tipo = 'H';
		     h = new herbivoro(*dynamic_cast<herbivoro*>(v->at(i))); // si es un herbivoro, se crea un objeto de tipo herbivoro
		}
		else if (dynamic_cast<omnivoro*>(v->at(i))) // si es un omnivoro
		{
			tipo = 'O';
			 o = new omnivoro(*dynamic_cast<omnivoro*>(v->at(i))); // si es un omnivoro, se crea un objeto de tipo omnivoro
		}
		else if (dynamic_cast<planta*>(v->at(i))) // si es una planta
		{
			tipo = 'P';
			 p = new planta(*dynamic_cast<planta*>(v->at(i))); // si es una planta, se crea un objeto de tipo planta
		}
		else if (dynamic_cast<agua*>(v->at(i))) // si es agua
		{
			tipo = 'A';
			 a = new agua(*dynamic_cast<agua*>(v->at(i))); // si es agua, se crea un objeto de tipo agua
		}
		switch (tipo)
		{
		case 'C': // Carnivoro
			ss << *c << endl;
			break;
		case 'H': // Herbivoro
			ss <<  *h << endl;
			break;
		case 'O': // Omnivoro
			ss << *o << endl;
			break;
		case 'P': // Planta
			ss << *p << endl;
			break;
		case 'A': // Agua
			ss << *a << endl;
			break;
		default:
			break;
		}
	}
	return ss.str();
}

template<class T>
inline string coleccionVector<T>::mostrarObjeto(string id)
{
	stringstream s;
	agua* a = nullptr; // inicializar punteros a null
	planta* p = nullptr; // inicializar punteros a null
	carnivoro* c = nullptr; // inicializar punteros a null
	herbivoro* h = nullptr; // inicializar punteros a null
	omnivoro* o = nullptr; // inicializar punteros a null
	for (int i = 0; i < v->size(); i++) {
		if (dynamic_cast<carnivoro*>(v->at(i))) {
			c = new carnivoro(*dynamic_cast<carnivoro*>(v->at(i))); // si es un carnivoro, se crea un objeto de tipo carnivoro
			if (c->getId() == id) { // si el id del objeto es igual al id del objeto buscado
				s << c->toString(); // se muestra el objeto
				return s.str();
			}
			return ""; // si no se encuentra el objeto, se retorna una cadena vacia
		}
		else if (dynamic_cast<herbivoro*>(v->at(i))) {
			h = new herbivoro(*dynamic_cast<herbivoro*>(v->at(i))); // si es un herbivoro, se crea un objeto de tipo herbivoro
			if (h->getId() == id) { // si el id del objeto es igual al id del objeto buscado
				s << h->toString(); // se muestra el objeto
				return s.str();
			}
			return ""; // si no se encuentra el objeto, se retorna una cadena vacia
		}
		else if (dynamic_cast<omnivoro*>(v->at(i))) {
			o = new omnivoro(*dynamic_cast<omnivoro*>(v->at(i))); // si es un omnivoro, se crea un objeto de tipo omnivoro
			if (o->getId() == id) { // si el id del objeto es igual al id del objeto buscado
				s << o->toString(); // se muestra el objeto
				return s.str();
			}
			return ""; // si no se encuentra el objeto, se retorna una cadena vacia
		}
		else if (dynamic_cast<planta*>(v->at(i))) {
			p = new planta(*dynamic_cast<planta*>(v->at(i))); // si es una planta, se crea un objeto de tipo planta
			if (p->getId() == id) { // si el id del objeto es igual al id del objeto buscado
				s << p->toString(); // se muestra el objeto
				return s.str();
			}
			return ""; // si no se encuentra el objeto, se retorna una cadena vacia
		}
		else if (dynamic_cast<agua*>(v->at(i))) {
			a = new agua(*dynamic_cast<agua*>(v->at(i))); // si es agua, se crea un objeto de tipo agua
			if (a->getId() == id) { // si el id del objeto es igual al id del objeto buscado
				s << a->toString(); // se muestra el objeto
				return s.str();
			}
			return ""; // si no se encuentra el objeto, se retorna una cadena vacia
		}
	}
	return ""; // si no se encuentra el objeto, se retorna una cadena vacia
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
	return new iteradorVector<T>(this->v); //correccion de iterador, antes tenia un iterados y no IteradorVector
}
#endif // !COLECCIONVECTOR_H












