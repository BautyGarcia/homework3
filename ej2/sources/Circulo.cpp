#include "../headers/Circulo.hpp"

Circulo::Circulo(Punto& centro, float radio) : 
    centro(centro), 
    radio(radio) 
{}

float Circulo::getRadio() const { return radio; }

Punto Circulo::getCentro() const { return centro; } 