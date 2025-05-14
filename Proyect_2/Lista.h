#pragma once
#include <iostream>
#include <sstream>
#include "Nodo.h"
using namespace std;
class Persona;
template <typename T>
class Lista {
private:
    Nodo<T>* dummy;

public:
    Lista();
    ~Lista();
    //---------------------------------------------------------------------
    Nodo<T>* getDummy();
    //---------------------------------------------------------------------
    string mostrarLista() const; 
    bool buscarElemento(T elemento) const;
    bool eliminarElemento(T elemento);
    void agregarElemento(T elemento);
    //---------------------------------------------------------------------
};

template<typename T>
Lista<T>::Lista() {
    dummy = new Nodo<T>();  // Nodo centinela
}

template<typename T>
Lista<T>::~Lista() {
    Nodo<T>* actual = dummy;
    while (actual) {
        Nodo<T>* temp = actual;
        actual = actual->getSiguiente();
        delete temp;
    }
}

template<typename T>
Nodo<T>* Lista<T>::getDummy() { return dummy->getSiguiente(); }

template<typename T>
void Lista<T>::agregarElemento(T elemento) {
    Nodo<T>* nuevo = new Nodo<T>(elemento);
    Nodo<T>* aux = dummy;
    while (aux->getSiguiente() != nullptr) {
        aux = aux->getSiguiente();
    }
    aux->setSiguiente(nuevo);
}

template<typename T>
string Lista<T>::mostrarLista() const {
    stringstream s;
    if (!dummy->getSiguiente())
        s << "No hay personas registradas...\n";

    Nodo<T>* aux = dummy->getSiguiente();
    while (aux != nullptr) {
        s << *aux->getDato() << "\n"; //sobrecargado
        aux = aux->getSiguiente();
    }

    return s.str();
}

template<typename T>
bool Lista<T>::buscarElemento(T elemento) const {
    Nodo<T>* aux = dummy->getSiguiente();
    while (aux != nullptr) {
        if (*aux->getDato() == *elemento) { //ahora si compara lso datos no sus punteros
            return true;               // desredefenciamos para poder acceder a los objetos persona
        }
        aux = aux->getSiguiente();
    }
    return false;
}

template<typename T>  
bool Lista<T>::eliminarElemento(T elemento) {  
    Nodo<T>* anterior = dummy;  
    Nodo<T>* actual = dummy->getSiguiente();  

    while (actual != nullptr) {  
        if (*actual->getDato() == *elemento) {  
            anterior->setSiguiente(actual->getSiguiente());  
            actual->setSiguiente(nullptr); // Asegurarse de desvincular el nodo antes de eliminarlo  
            delete actual;  
            return true;  
        }  
        anterior = actual;  
        actual = actual->getSiguiente();  
    }  
    return false;  
}
