#include "planta.h"

planta::planta(string id) : recurso(id,"P") {}
planta::~planta() {}

string planta::toString() {
	stringstream s;
	s << recurso::toString();
	return s.str();
}