#include "../headers/pokemonInfo.h"
#include <fstream>

// Constructor mediante lista de inicialización
PokemonInfo::PokemonInfo(const string& tipoPokemon, const string& descripcionPokemon, map<string, int>& ataquesPorNivel, vector<int>& experienciaNivel): tipo(tipoPokemon), descripcion(descripcionPokemon), ataquesDisponiblesPorNivel(ataquesPorNivel), experienciaProximoNivel(experienciaNivel) {};

// Getters
string PokemonInfo::getTipo() const { return tipo; }
string PokemonInfo::getDescripcion() const { return descripcion; }
map<string, int> PokemonInfo::getAtaquesDisponiblesPorNivel() const { return ataquesDisponiblesPorNivel; }
vector<int> PokemonInfo::getExperienciaProximoNivel() const { return experienciaProximoNivel; }

// Setters
void PokemonInfo:: setTipo(string& nuevoTipo) {
    tipo = nuevoTipo;
}

//Serializacion
void PokemonInfo::serializar(ofstream& out) const {
    size_t tipoSize = tipo.size(); 
    size_t descripcionSize = descripcion.size();
    
    //Tipo
    out.write(reinterpret_cast<const char*>(&tipoSize), sizeof(tipoSize));
    out.write(tipo.c_str(), tipoSize);
    
    //Descripcion
    out.write(reinterpret_cast<const char*>(&descripcionSize), sizeof(descripcionSize));
    out.write(descripcion.c_str(), descripcionSize);
    
    //Ataques disponibles por nivel
    size_t ataquesSize = ataquesDisponiblesPorNivel.size();
    //Guarda el tamaño del mapa
    out.write(reinterpret_cast<const char*>(&ataquesSize), sizeof(ataquesSize));
    for (const auto& ataque : ataquesDisponiblesPorNivel) {
        //Serializamos desempaquetando cada par key-value
        size_t ataqueSize = ataque.first.size();
        out.write(reinterpret_cast<const char*>(&ataqueSize), sizeof(ataqueSize));
        out.write(ataque.first.c_str(), ataqueSize);
        out.write(reinterpret_cast<const char*>(&ataque.second), sizeof(ataque.second));
    }

    //Experiencia proximo nivel
    size_t experienciaSize = experienciaProximoNivel.size();
    out.write(reinterpret_cast<char*>(&experienciaSize), sizeof(experienciaSize));
    out.write(reinterpret_cast<char*>(const_cast<int*>(experienciaProximoNivel.data())), experienciaSize * sizeof(int));
}

//Deserializacion
void PokemonInfo:: deserializar(ifstream& in){
    //Tipo
    size_t tipoSize = tipo.size();
    in.read(reinterpret_cast<char*>(&tipoSize), sizeof(tipoSize));
    tipo.resize(tipoSize);
    in.read(&tipo[0], tipoSize);
    
    //Descripcion
    size_t descripcionSize = descripcion.size();
    in.read(reinterpret_cast<char*>(&descripcionSize), sizeof(descripcionSize));
    descripcion.resize(descripcionSize);
    in.read(&descripcion[0], descripcionSize);
    
    //Ataques disponibles por nivel
    size_t ataquesSize = ataquesDisponiblesPorNivel.size();
    in.read(reinterpret_cast<char*>(&ataquesSize), sizeof(ataquesSize));
    for (const auto& ataque : ataquesDisponiblesPorNivel) {
        //Serializacion del nombre del ataque
        size_t nombreAtaqueSize = ataque.first.size();
        in.read(reinterpret_cast<char*>(&nombreAtaqueSize), sizeof(nombreAtaqueSize));
        in.read(&ataque.first[0], nombreAtaqueSize);
        
        //Serializamos el nivel del ataque
        int nivelAtaque;
        in.read(reinterpret_cast<char*>(&nivelAtaque), sizeof(ataque.nivelAtaque));

    }
    
    //Experiencia proximo nivel
    size_t experienciaSize = experienciaProximoNivel.size();
    in.read(reinterpret_cast<char*>(&experienciaSize), sizeof(experienciaSize));
    experienciaProximoNivel.resize(experienciaSize);
    in.read(reinterpret_cast<char*>(experienciaProximoNivel.data()), experienciaSize * sizeof(int));
    
    in.close();
}