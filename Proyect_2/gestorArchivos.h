#pragma once
#ifndef GESTOR_ARCHIVOS_H
#define GESTOR_ARCHIVOS_H
#include <iostream>
#include <fstream>
#include <string>
#include "coleccionVector.h"
#include "Matriz.h"
#include "elemento.h"
using namespace std;
#define DELIMITA_ELEMENTO '\t'
#define	DELIMITA_REGISTRO '\n'
//-----------------------------//
ifstream entrada("save.txt");
ofstream salida("save.txt", ios::out);
//----------------------------//
bool guardar(coleccionVector<elemento>*);
bool cargar(coleccionVector<elemento>*);
int stringAInt( const string& texto);
#endif 
