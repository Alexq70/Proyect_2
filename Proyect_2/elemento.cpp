#include "elemento.h"

bool elemento::operator==(elemento& other)
{
	if (this->id == other.id) {
		return true;
	}
}

elemento::elemento(char tipo, string id,coordenada p)
{
	this->id = id;
	this->tipo = tipo;
	this->posicion.setX(p.getX());
}

string elemento::toString()
{
	stringstream s;
	s << "Elemento: " << endl
		<< "ID: " << id << endl
		<< "Posicion: (" << posicion.getX() << ", " << posicion.getY() << ")" << endl
		<< "Tipo: " << tipo << endl;
	return s.str();
}

string elemento::getId()
{
	return this->id;
}

char elemento::getTipo()
{
	return this->tipo;
}

coordenada elemento::getCoordenada()
{
	return this->posicion;
}

ostream& operator<<(ostream& os, elemento& e)
{
	os << e.toString();
	return os;
}
