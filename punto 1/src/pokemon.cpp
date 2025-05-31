#include "../include/pokemon.h"
#include <fstream>

//Constructor 
Pokemon::Pokemon() {};
//Constructor mediante lista de inicialización
Pokemon::Pokemon(const string& nombrePoke, int experienciaPoke): nombre(nombrePoke), experiencia(experienciaPoke) {};

//Getters
string Pokemon::getNombre() const { return nombre; }
int Pokemon::getExperiencia() const { return experiencia; }

//Setters
void Pokemon:: setExperiencia(int nuevaExperiencia) {
    if (experiencia < 0 && nuevaExperiencia >= 0) experiencia = nuevaExperiencia;
}

//Serializacion
void Pokemon::serializar(ofstream& out) const {
    //Nombre
    size_t nombreSize = nombre.size();
    //Guarda el tamaño del nombre
    out.write(reinterpret_cast<const char*>(&nombreSize), sizeof(nombreSize));
    out.write(nombre.c_str(), nombreSize);
    
    //Experiencia
    out.write(reinterpret_cast<const char*>(&experiencia), sizeof(experiencia));
}

//Deserializacion
void Pokemon::deserializar(ifstream& in){
    size_t nombreSize;
    //Nombre
    in.read(reinterpret_cast<char*>(&nombreSize), sizeof(nombreSize));
    nombre.resize(nombreSize); 
    in.read(&nombre[0], nombreSize);
    
    //Experiencia
    in.read(reinterpret_cast<char*>(&experiencia), sizeof(experiencia));
}
