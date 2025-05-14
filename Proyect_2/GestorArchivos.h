#pragma once
#include "Lista.h"
#include "Persona.h"
#include <fstream>
#include <string>

class GestorArchivos {
public:
    static void guardarPersonas(Lista<Persona*>* lista, const string& nombreArchivo);
    static void cargarPersonas(Lista<Persona*>* lista, const string& nombreArchivo);
};


