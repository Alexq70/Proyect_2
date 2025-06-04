#include "Matriz.h"

matriz::matriz()
{
	this->iterador = nullptr;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			m[i][j] = nullptr; // Inicializar la matriz con punteros nulos
		}
	}
}

matriz::matriz(coleccionVector<elemento>* c)
{
	this->iterador = c->getIterador();
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			m[i][j] = nullptr; // Inicializar la matriz con punteros nulos
		}
	}
}

bool matriz::insertarElemneto(elemento* e, int x, int y)
{
	if (m[x][y] == nullptr) {
		m[x][y] = e;
	}
		return false; // Si la posicion ya esta ocupada, no se inserta el elemento
	}
	return true;
}

bool matriz::eliminarElemento(int x, int y)
{
	if (m[x][y] != nullptr) {
		delete m[x][y]; // Liberar memoria del elemento
		m[x][y] = nullptr; // Marcar la posición como vacía
		return true; // Eliminación exitosa
	}
	else {
		return false;// ya esta vacio
	}
}

string matriz::mostrarMatriz()
{
	stringstream ss;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (m[i][j] != nullptr) {
				ss << this->iterador->current();
			}
		}
	}
	return ss.str();
}