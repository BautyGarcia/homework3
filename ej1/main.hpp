#include <fstream>
#include <iostream>
#include <memory>

using namespace std;

class IMediciones {
    public:
        virtual void serializar(ostream& out) const = 0;
        virtual void deserializar(ifstream& in) = 0;
        virtual ~IMediciones() = default;
};

class MedicionBase: public IMediciones {
    protected:
        unique_ptr<float> tiempoMedicion;
    public:
        MedicionBase(float tiempoMedicion);
        virtual void serializar(ostream& out) const override;
        virtual void deserializar(ifstream& in) override;
        float getTiempo() const;
        virtual void imprimir() const = 0;
        virtual ~MedicionBase() = default;
};

class Presion: public MedicionBase {
    public:
        float presionEstatica;
        float presionDinamica;
        Presion(float presionEstatica, float presionDinamica, float tiempoMedicion);
        void serializar(ostream& out) const override;
        void deserializar(ifstream& in) override;
        void imprimir() const override;
        ~Presion() = default;
};

class Posicion: public MedicionBase {
    public:
        float latitud;
        float longitud;
        float altitud;
        Posicion(float latitud, float longitud, float altitud, float tiempoMedicion);
        void serializar(ostream& out) const override;
        void deserializar(ifstream& in) override;
        void imprimir() const override;
        ~Posicion() = default;
};

class SaveFlightData {
    public:
        shared_ptr<Posicion> posicion;
        shared_ptr<Presion> presion;
        SaveFlightData(const Posicion& posicion, const Presion& presion);
        void serializar(ostream & out) const;
        void deserializar(ifstream & in);
        void imprimir() const;
        ~SaveFlightData() = default;
};
