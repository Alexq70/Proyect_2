#include "observerVector.h"
#include "coleccionVector.h"

observerVector::observerVector(coleccionVector<elemento>* c)
{
	this->coleccion = c; 
	this->coleccion->agregarObserver(this); 
}
