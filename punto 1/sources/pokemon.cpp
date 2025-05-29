#include "../headers/pokemon.h"
#include <fstream>

//Constructor mediante lista de inicialización
Pokemon::Pokemon(string nombrePokemon, int experienciaPokemon): nombre(nombrePokemon), experiencia(experienciaPokemon) {};

//Getters
string Pokemon::getNombre() const { return nombre; }
int Pokemon::getExperiencia() const { return experiencia; }

//Setters
void Pokemon:: setExperiencia(int nuevaExperiencia) {
    if (experiencia < 0 && nuevaExperiencia >= 0) experiencia = nuevaExperiencia;
}

//Serializacion
void Pokemon::serializar(const string& path) const {
    ofstream out(path, ios::binary);
    if (out.is_open()) {
        out.write(reinterpret_cast<const char*>(&nombre), sizeof(nombre));
        out.write(reinterpret_cast<const char*>(&experiencia), sizeof(experiencia));
        out.close();
    }
}

//Deserializacion
void Pokemon::deserializar(const string& path){
    ifstream in(path, ios:: binary);
    if (in.is_open()){
        in.read(reinterpret_cast<char*>(&nombre), sizeof(nombre));
        in.read(reinterpret_cast<char*>(&experiencia), sizeof(experiencia));
        in.close();
    }
}