#pragma once
#include <iostream>
#include <string>
using namespace std;
class Persona {
private:
    std::string nombre;
    int edad;
    std::string cedula;

public:
    // Constructor
    Persona(std::string _nombre, string _cedula, int _edad) {
        nombre = _nombre;
        edad = _edad;
        cedula = _cedula;
    }
    string getNombre() const {
        return nombre;
	}   
    string getCedula() const {
        return cedula;
    }
    int getEdad() const {
        return edad;
	}   
    bool operator==(const Persona& otra) const {
        return nombre == otra.nombre && edad == otra.edad && cedula == otra.cedula;
    }

    friend ostream& operator<<(ostream& s, Persona&  p) {
		return s << "Nombre: " << p.nombre << ", Edad: " << p.edad << ", cedula: " << p.cedula;
    }
};



