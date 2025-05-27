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


};