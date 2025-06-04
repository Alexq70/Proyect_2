#include "recurso.h"
#include "elemento.h"
recurso::recurso(char tipo, string id, coordenada p) :elemento(tipo, id,p)
{
	this->posicion = p;
}
