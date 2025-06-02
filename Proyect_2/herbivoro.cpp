#include "herbivoro.h"

herbivoro::herbivoro(string id,int energia, int edad,coordenada p) : criatura(id,"H",energia,edad,p) {}
herbivoro::~herbivoro() {}

string herbivoro::toString() {
	stringstream s;
	s << criatura::toString() << endl;
	return s.str();
}