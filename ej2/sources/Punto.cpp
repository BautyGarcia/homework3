#include "../headers/Punto.hpp"

Punto::Punto(float x, float y) : x(x), y(y) {}

float Punto::getX() const { return x; }

float Punto::getY() const { return y; } 

void Punto::setX(float x) { this->x = x; }

void Punto::setY(float y) { this->y = y; }