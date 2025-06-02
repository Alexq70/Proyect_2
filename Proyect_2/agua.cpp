#include "agua.h"

agua::agua(string id,coordenada p): recurso(id,"A",p) {}
agua::~agua() {}

string agua::toString() {
	stringstream s;
	s << recurso::toString();
	return s.str();
}