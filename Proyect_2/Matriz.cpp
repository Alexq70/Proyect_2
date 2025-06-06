#include "Matriz.h"
matriz::matriz(coleccionVector<elemento*>* c) : observerVector(c)
{
	this->iterador = c->getIterador();
	
}

void matriz::actualizar()
{

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			m[i][j] = nullptr;
		}
	}

	this->iterador->first();
	while (!this->iterador->isDone()) {
		elemento* e = *this->iterador->current();
		int x = e->getCoordenada().getX();
		int y = e->getCoordenada().getY();
		if (x >= 0 && x < 15 && y >= 0 && y < 15) { // Verificar que las coordenadas est�n dentro del rango
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
		m[x][y] = nullptr; // Marcar la posici�n como vac�a
		return true; // Eliminaci�n exitosa
	}
	else {
		return false;// ya esta vacio
	}
}
elemento* matriz::verificarCoordenada(coordenada c) {

	if (m[c.getX()][c.getY()] == nullptr) {
		return nullptr; // no hay nada en esa coordenada
	}
	return m[c.getX()][c.getY()];
}



string matriz::mostrarMatriz()
{
	stringstream ss;
	for (int i = 0; i < 15; i++) {
		if (i > 0) {
			ss << endl; // Nueva l�nea entre filas
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
	actualizar(); // Actualizar la matriz tras la eliminaci�n del elemento
}

coordenada matriz::coordenadaDisponibleM(coordenada c)
{
	if (c.getX() >= 0 && c.getX() < 15 && c.getY() >= 0 && c.getY() < 15) {
		if (m[c.getX()][c.getY()] == nullptr) {
			return c; // Si la posici�n est� vac�a, devolver la coordenada
		}
		else {
			return coordenada(-1, -1); // Si la posici�n est� ocupada, devolver una coordenada inv�lida
		}
	}
	else {
		return coordenada(-1, -1); // Coordenada fuera de rango
	}
}



coordenada matriz::coordenadaRandom()
{
	static random_device rd;
	static mt19937 gen(rd());
	static uniform_int_distribution<> dis(0, 14);
	int x = dis(gen);
	int y = dis(gen);
	if (m[x][y] == nullptr) {
		return coordenada(x, y); // Si la posici�n est� vac�a, devolver la coordenada
	}
	else {
		return coordenadaRandom(); // Si la posici�n est� ocupada, generar otra coordenada aleatoria
	}

}
