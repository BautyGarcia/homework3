#include "../headers/Circulo.hpp"

Circulo::Circulo(Punto& centro, float radio) : 
    centro(centro), 
    radio(radio) 
{}

float Circulo::getRadio() const { return radio; }

Punto Circulo::getCentro() const { return centro; } 

void Circulo::setRadio(float radio) { this->radio = radio; }

void Circulo::setCentro(Punto& centro) { this->centro = centro; }