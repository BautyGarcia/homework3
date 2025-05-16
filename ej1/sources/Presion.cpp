#include "../headers/Presion.hpp"
#include <iostream>
#include <fstream>

Presion::Presion(float presionEstatica, float presionDinamica, float tiempoMedicion) : 
    MedicionBase(tiempoMedicion),
    presionEstatica(presionEstatica),
    presionDinamica(presionDinamica) 
{}

void Presion::serializar(std::ostream& out) const {
    MedicionBase::serializar(out);
    out.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(presionEstatica));
    out.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(presionDinamica));
}

void Presion::deserializar(std::ifstream& in) {
    MedicionBase::deserializar(in);
    in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(presionEstatica));
    in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(presionDinamica));
}

void Presion::imprimir() const {
    std::cout << "Presion Estatica: " << presionEstatica << std::endl;
    std::cout << "Presion Dinamica: " << presionDinamica << std::endl;
    std::cout << "Tiempo de Medicion: " << getTiempo() << std::endl;
} 