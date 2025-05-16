#include "../headers/Elipse.hpp"

Elipse::Elipse(Punto& centro, float semiejeMayor, float semiejeMenor) : 
    centro(centro), 
    semiejeMayor(semiejeMayor), 
    semiejeMenor(semiejeMenor) 
{}

float Elipse::getSemiejeMayor() const { return semiejeMayor; }

float Elipse::getSemiejeMenor() const { return semiejeMenor; }

Punto Elipse::getCentro() const { return centro; } 