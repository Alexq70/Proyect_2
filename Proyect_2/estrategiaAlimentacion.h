#pragma once

#include "estrategia.h"
class matriz;
class estrategiaAlimentacion : public estrategia {
public:
    virtual void realizarEstrategia(elemento*, elemento*, matriz*) = 0;
};

