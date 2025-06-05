#include "Matriz.h"
matriz::matriz(coleccionVector<elemento*>* c) : observerVector(c)
{
	this->iterador = c->getIterador();
	
}

void matriz::actualizar()
{
	this->iterador->first();
	while (!this->iterador->isDone()) {
		elemento* e = *this->iterador->current();
		int x = e->getCoordenada().getX();
		int y = e->getCoordenada().getY();
		if (x >= 0 && x < 10 && y >= 0 && y < 15) { // Verificar que las coordenadas estén dentro del rango
			m[x][y] = e; // Insertar el elemento en la matriz
		}
		this->iterador->next();
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

void matriz::updateCreacion()
{
	actualizar(); // Actualizar la matriz con el nuevo elemento
}

void matriz::updateEliminacion()
{
	actualizar(); // Actualizar la matriz tras la eliminación del elemento
}
