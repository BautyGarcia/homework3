#include "main.hpp"

Punto::Punto(float x, float y) : x(x), y(y) {};

float Punto::getX() const { return x; };

float Punto::getY() const { return y; };

Rectangulo::Rectangulo(Punto& verticeInferiorIzquierdo, float ancho, float alto) : 
    posicion(verticeInferiorIzquierdo), 
    ancho(ancho), 
    alto(alto) 
{};

float Rectangulo::getAncho() const { return ancho; };

float Rectangulo::getAlto() const { return alto; };

Punto Rectangulo::getPosicion() const { return posicion; };

Circulo::Circulo(Punto& centro, float radio) : 
    centro(centro), 
    radio(radio) 
{};

float Circulo::getRadio() const { return radio; };

Punto Circulo::getCentro() const { return centro; };

Elipse::Elipse(Punto& centro, float semiejeMayor, float semiejeMenor) : 
    centro(centro), 
    semiejeMayor(semiejeMayor), 
    semiejeMenor(semiejeMenor) 
{};

float Elipse::getSemiejeMayor() const { return semiejeMayor; };

float Elipse::getSemiejeMenor() const { return semiejeMenor; };

Punto Elipse::getCentro() const { return centro; };

int main() {
    Punto p1(0.0f, 0.0f);
    Punto p2(1.0f, 2.0f);
    Punto p3(-3.0f, 4.0f);

    Rectangulo rect(p1, 5.0f, 3.0f);
    Circulo circ(p2, 2.0f);
    Elipse elip(p3, 4.0f, 1.5f);

    ProcesadorFigura<Rectangulo> procRect;
    ProcesadorFigura<Circulo> procCirc;
    ProcesadorFigura<Elipse> procElip;

    cout << "Area del rectangulo: " << procRect.calcularArea(rect) << endl;
    cout << "Area del circulo: " << procCirc.calcularArea(circ) << endl;
    cout << "Area de la elipse: " << procElip.calcularArea(elip) << endl;

    // Caso generico donde no va a funcionar
    ProcesadorFigura<Punto> procPunto;
    procPunto.calcularArea(p1);

    return 0;
}
