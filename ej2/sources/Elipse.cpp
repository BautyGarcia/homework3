#include "../headers/Elipse.hpp"

Elipse::Elipse(Punto& centro, float semiejeMayor, float semiejeMenor) : 
    centro(centro), 
    semiejeMayor(semiejeMayor), 
    semiejeMenor(semiejeMenor) 
{}

float Elipse::getSemiejeMayor() const { return semiejeMayor; }

float Elipse::getSemiejeMenor() const { return semiejeMenor; }

Punto Elipse::getCentro() const { return centro; } 

void Elipse::setSemiejeMayor(float semiejeMayor) { this->semiejeMayor = semiejeMayor; }

void Elipse::setSemiejeMenor(float semiejeMenor) { this->semiejeMenor = semiejeMenor; }

void Elipse::setCentro(Punto& centro) { this->centro = centro; }