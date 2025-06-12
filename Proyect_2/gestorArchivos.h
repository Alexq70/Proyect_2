#pragma once
#ifndef GESTOR_ARCHIVOS_H
#define GESTOR_ARCHIVOS_H
#include <iostream>
#include <fstream>
#include <string>
#include "coleccionVector.h"
#include "Matriz.h"
#include "elemento.h"
#include "carnivoro.h"
#include "herbivoro.h"
#include "omnivoro.h"
#include "agua.h"
#include "planta.h"
using namespace std;
#define DELIMITA_REGISTRO ','
#define DELIMITA_ELEMENTO '\n'
//----------------------------//
bool guardar(coleccionVector<elemento>*);
bool cargar(coleccionVector<elemento>*);
int stringAInt( const string& texto);
#endif 
