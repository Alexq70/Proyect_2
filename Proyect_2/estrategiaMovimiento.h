#pragma once

#include "estrategia.h"
class matriz;
class estrategiaMovimiento : public estrategia {
public:
    virtual void realizarEstrategia(elemento*, matriz*) = 0;
};

