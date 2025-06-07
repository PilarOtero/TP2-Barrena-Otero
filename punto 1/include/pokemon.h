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

        //Carga y descarga de información del Pokemon a archivo
        void cargarInfo(ofstream& out) const;   
        void descargarInfo(ifstream& in);

        //Destructor
        ~Pokemon() = default;
};


//Functor para el hash de Pokemon
struct PokemonHash {
    public:
        //Sobrecarga del operador ()
        size_t operator()(const Pokemon& pokemon) const {
            return hash<string>()(pokemon.getNombre());
        }
};


