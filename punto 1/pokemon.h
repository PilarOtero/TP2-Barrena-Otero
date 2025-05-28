#pragma once
#include <string>

using namespace std;

class Pokemon {
    private:
        string nombre;
        int experiencia;
    
    public:
        //Constructor
        Pokemon(string nombrePokemon, int experienciaPokemon);
        
        //Getters
        string getNombre() const;
        int getExperiencia() const;

        //Setters
        void setExperiencia(int nuevaExperiencia);

        //Hash function para Pokemon
        bool operator==(const Pokemon& other) const {
            return nombre == other.nombre;
        }
};

class PokemonHash {
    public:
        size_t operator()(const Pokemon& pokemon) const {
            return hash<string>()(pokemon.getNombre());
        }
};


