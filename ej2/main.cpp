#include "headers/Punto.hpp"
#include "headers/Rectangulo.hpp"
#include "headers/Circulo.hpp"
#include "headers/Elipse.hpp"
#include "headers/ProcesadorFigura.hpp"
#include <iostream>

using namespace std;

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
