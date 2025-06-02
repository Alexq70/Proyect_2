#include "agua.h"

agua::agua(string id): recurso(id,"A") {}
agua::~agua() {}

string agua::toString() {
	stringstream s;
	s << recurso::toString();
	return s.str();
}