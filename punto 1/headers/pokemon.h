#pragma once
#include <string>
#include <fstream>

using namespace std;

class Pokemon {
    private:
        string nombre;
        int experiencia;
    
    public:
        //Constructores
        Pokemon();
        Pokemon(const string& nombrePoke, int experienciaPoke);
        
        //Getters
        string getNombre() const;
        int getExperiencia() const;

        //Setters
        void setExperiencia(int nuevaExperiencia);

        //Hash function para Pokemon
        bool operator==(const Pokemon& other) const {
            return nombre == other.nombre;
        }

        //Serializacion y deserializacion
        void serializar(ofstream& out) const;   
        void deserializar(ifstream& in);

        //Destructor
        ~Pokemon() = default;
};

class PokemonHash {
    public:
        size_t operator()(const Pokemon& pokemon) const {
            return hash<string>()(pokemon.getNombre());
        }
};


