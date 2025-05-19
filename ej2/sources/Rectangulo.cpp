#include "../headers/Rectangulo.hpp"

Rectangulo::Rectangulo(Punto& verticeInferiorIzquierdo, float ancho, float alto) : 
    posicion(verticeInferiorIzquierdo), 
    ancho(ancho), 
    alto(alto) 
{}

float Rectangulo::getAncho() const { return ancho; }

float Rectangulo::getAlto() const { return alto; }

Punto Rectangulo::getPosicion() const { return posicion; } 

void Rectangulo::setAncho(float ancho) { this->ancho = ancho; }

void Rectangulo::setAlto(float alto) { this->alto = alto; }

void Rectangulo::setPosicion(Punto& posicion) { this->posicion = posicion; }