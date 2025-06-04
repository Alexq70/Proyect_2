#include "Matriz.h"

matriz::matriz()
{
	this->iterador = nullptr;
			m[i][j] = nullptr; // Inicializar la matriz con punteros nulos
		}
	}
}

{
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
		;
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
			if (m[i][j] != nullptr) {
			}
		}
	}
	return ss.str();
}