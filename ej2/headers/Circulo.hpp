#ifndef CIRCULO_HPP
#define CIRCULO_HPP
#include "Punto.hpp"

class Circulo {
    public:
        Circulo(Punto& centro, float radio);
        float getRadio() const;
        Punto getCentro() const;
        ~Circulo() = default;
    private:
        Punto centro;
        float radio;
};

#endif 