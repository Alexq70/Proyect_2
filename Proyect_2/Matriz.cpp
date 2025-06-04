#include "Matriz.h"

matriz::matriz()
{
	this->iterador = nullptr;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 15; j++) {
			m[i][j] = nullptr; // Inicializar la matriz con punteros nulos
		}
	}
}

matriz::matriz(iteradorVector<elemento*>* c)
{
	this->iterador = c;
	c->first();
	while (!c->isDone()) {
		elemento* e = *c->current();
		int x = e->getCoordenada().getX();
		int y = e->getCoordenada().getY();
		if (x >= 0 && x < 10 && y >= 0 && y < 15) { // Verificar que las coordenadas estén dentro del rango
			m[x][y] = e; // Insertar el elemento en la matriz
		}
		c->next();
	}
}

bool matriz::insertarElemneto(elemento* e, int x, int y)
{
	if (m[x][y] == nullptr) {
		m[x][y] = e;
	}
	else {
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
	for (int i = 0; i < 10; i++) {
		if (i > 0) {
			ss << endl; // Nueva línea entre filas
		}
		for (int j = 0; j < 15; j++) {
			if (m[i][j] != nullptr) {
				ss << m[i][j]->getTipo();
			}
			else {
				ss << ".";
			}
		}
	}
	return ss.str();
}