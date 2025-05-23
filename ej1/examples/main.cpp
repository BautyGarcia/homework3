#include "../headers/SaveFlightData.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    try {
        // Creo los objetos originales
        Posicion posicionOriginal(-34.6f, -58.4f, 950.0f, 5.3f);
        Presion presionOriginal(101.3f, 5.8f, 6.1f);
        SaveFlightData saveFlightDataOriginal(posicionOriginal, presionOriginal);

        // Serializo
        ofstream outFile("datos_vuelo.bin", ios::binary);
        if (outFile.is_open()) {
            saveFlightDataOriginal.serializar(outFile);
            outFile.close();
        }
        
        // Creo objetos para deserializar
        Posicion posicionDeserializada(0.0f, 0.0f, 0.0f, 0.0f);
        Presion presionDeserializada(0.0f, 0.0f, 0.0f);
        SaveFlightData saveFlightDataDeserializado(posicionDeserializada, presionDeserializada);

        // Deserializo
        ifstream inFile("datos_vuelo.bin", ios::binary);
        if (inFile.is_open()) {
            saveFlightDataDeserializado.deserializar(inFile);
            inFile.close();
        }

        // Imprimir los datos deserializados
        cout << "Datos deserializados:" << endl;
        saveFlightDataDeserializado.imprimir();

        return 0;
    } catch (const std::bad_alloc& e) {
        cerr << "Error de memoria: " << e.what() << endl;
        return 1;
    } catch (...) {
        cerr << "Error." << endl;
        return 1;
    }
}