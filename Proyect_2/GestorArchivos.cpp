#include "GestorArchivos.h"

void GestorArchivos::guardarPersonas(Lista<Persona*>* lista, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) { //paso 1 verificar si el archuvo se puede abrir
        cerr << "Error: no se pudo abrir el archivo para guardar.\n";
        return;
    }

    Nodo<Persona*>* aux = lista->getDummy(); // agarra el primer elemento no el dummy
    while (aux != nullptr) {
        archivo << aux->getDato()->getNombre() << ','; // paso 2 recorrer la lista extrayendo los getDato()s de cada objeto
        archivo << aux->getDato()->getCedula() << ','; // meter esos getDato()s al archivo
        archivo << aux->getDato()->getEdad() << '\n';  // no olvidar el endl o separador
        aux = aux->getSiguiente();
    }

    archivo.close(); // cerrar el archivo
    cout << "Personas guardadas en " << nombreArchivo << "\n";
}

void GestorArchivos::cargarPersonas(Lista<Persona*>* lista, const string& nombreArchivo) {
    ifstream archivo(nombreArchivo); //(persona.txt) por ejemplo
    if (!archivo.is_open()) {  // paso 1: verificar si el archivo se puede abrir
        cerr << "Error: no se pudo abrir el archivo para cargar.\n";
        return;
    }

    string linea;  // línea completa a leer
    while (getline(archivo, linea)) {  // paso 2: leer línea por línea del archivo
        stringstream ss(linea);  // paso 3: convertir la línea a stream para dividirla
        string nombre, cedula, edadStr;

        // paso 4: extraer cada getDato() separado por coma
        if (getline(ss, nombre, ',') &&
            getline(ss, cedula, ',') &&
            getline(ss, edadStr)) {

            int edad = stoi(edadStr); // paso 5: conversión de edad a entero
            Persona* p = new Persona(nombre, cedula, edad); // paso 6: crear el objeto
            lista->agregarElemento(p); // paso 7: agregar el objeto a la lista
        }
    }

    archivo.close(); // paso 8: cerrar el archivo
    cout << "Personas cargadas desde " << nombreArchivo << "\n";
}