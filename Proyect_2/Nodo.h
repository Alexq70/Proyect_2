#pragma once

template <typename T>
class Nodo {
private:
	T dato;
	Nodo<T>* siguiente;
public:
	//---------------------------------------------------------------------
	Nodo();               // Constructor para dummy
	Nodo(T dato); // Constructor para nodo con dato
	//---------------------------------------------------------------------
	T getDato() const;
	Nodo<T>* getSiguiente () const;
	void setSiguiente(Nodo<T>* siguiente);
	void setDato(T dato);

	//---------------------------------------------------------------------
};

//---------------------------------------------------------------------
template <typename T>
Nodo<T>::Nodo() : dato(T()), siguiente(nullptr) {}    // Constructor para dummy
template <typename T>
Nodo<T>::Nodo(T dato) : dato(dato), siguiente(nullptr) {}

//---------------------------------------------------------------------
template <typename T>
T Nodo<T>::getDato() const { return dato; }
template <typename T>
Nodo<T>* Nodo<T>::getSiguiente() const { return siguiente; }
template <typename T>
void Nodo<T>::setSiguiente(Nodo<T>* siguiente) { this->siguiente = siguiente; }
template <typename T>
void Nodo<T>::setDato(T dato) { this->dato = dato; }
//---------------------------------------------------------------------
