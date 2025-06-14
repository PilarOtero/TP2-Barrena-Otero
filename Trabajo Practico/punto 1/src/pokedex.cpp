#include "../include/pokedex.h"

//Constructores
Pokedex::Pokedex() {};

Pokedex::Pokedex(const string& fileNamePokedex): fileName("build/bin/" + fileNamePokedex) {};

//Metodo para mostrar el nombre y tipo del Pokemon
void Pokedex::mostrar(const Pokemon& pokemon) const {
    auto it = pokedexMap.find(pokemon);
    if (it != pokedexMap.end()) {
        cout << "NOMBRE -> " << pokemon.getNombre() << "\nEXPERIENCIA -> " << pokemon.getExperiencia() << endl;
    }
    else {
        cout << "Pokemon desconocido!" << endl;
    }
}

//Metodo para mostrar la informacion del Pokemon
void Pokedex::mostrarInfo(const Pokemon& pokemon) const {
    auto it = pokedexMap.find(pokemon);
    if (it != pokedexMap.end()) {
        const PokemonInfo& info = it->second;
        cout << "TIPO -> " << info.getTipo() << "\nDESCRIPCIÓN -> " << info.getDescripcion() << "\n";
        
        const auto& ataques = info.getAtaquesDisponiblesPorNivel();
        cout << "ATAQUES " << endl;
        for (auto it = ataques.begin(); it!= ataques.end(); ++it) {
            cout << "- "<< it->first << " -> Puntaje de daño: " << it->second << endl;

        }

        const auto& experiencia = info.getExperienciaProximoNivel();
        cout << "EXPERIENCIA PROXIMO NIVEL " << endl;
        for (size_t i = 0; i < experiencia.size(); i++){
            cout << "- " << experiencia[i] << endl;
        }
    }

    else {
        cout << "Pokemon desconocido!" << endl;
    }
}

//Metodo para agregar un Pokemon a la Pokedex
void Pokedex:: agregarPokemon(Pokemon& NuevoPokemon, const PokemonInfo& nuevoinfo) {
    //Si el Pokemon no pertenece a la Pokedex,se agrega
    if (pokedexMap.find(NuevoPokemon) == pokedexMap.end()) {
        pokedexMap.insert({NuevoPokemon, nuevoinfo});
        if (!fileName.empty()){
            //Se agrega la nueva información al archivo
            cout << "Guardando a " << NuevoPokemon.getNombre() << " en el archivo " << fileName << "..." << endl;
            cout << "---------------------------------------------------------------" << endl;
            cargarInfo();
        }
    }
    else {
        cout << "El Pokemon ya pertenece a Pokedex" << endl;
    }
}

//Carga de información al archivo binario
void Pokedex::cargarInfo() const {
    ofstream out(fileName, ios::binary);
    if (!out.is_open()){
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    //Guarda el tamaño del mapa
    size_t size = pokedexMap.size();
    out.write(reinterpret_cast<const char*>(&size), sizeof(size));
    for (const auto& par: pokedexMap){
        //Carga del nombre y experiencia del Pokemon
        par.first.cargarInfo(out);
        //Carga del tipo, descripción, ataques disponibles por nivel y experiencia próximo nivel del Pokemon
        par.second.cargarInfo(out);
    }
    out.close();
}

//Descarga de información del archivo binario
void Pokedex::descargarInfo(){
    ifstream in(fileName, ios::binary);
    if (!in.is_open()){
        cout << "Error al abrir el archivo" << endl;
        return;
    }
    //Limpiamos antes de cargar la información
    pokedexMap.clear();

    size_t size;
    in.read(reinterpret_cast<char*>(&size), sizeof(size));
    for(size_t i = 0; i < size; ++i){
        Pokemon pokemon;
        PokemonInfo info;
        //Obtención del nombre y experiencia del Pokemon
        pokemon.descargarInfo(in);
        //Obtención de la información del Pokemon (tipo, descripción, ataques disponibles por nivel y experiencia próximo nivel)
        info.descargarInfo(in);
        //Agregado del Pokemon y su info al mapa
        pokedexMap[pokemon] = info;
    }
    in.close();
}

//Método para mostrar todos los Pokemones
void Pokedex::mostrarTodos() const {
    if (pokedexMap.empty()) {
        cout << "La Pokedex esta vacia" << endl;
        return;
    }

    for (const auto& par:pokedexMap){
        const Pokemon& pokemon = par.first;
        mostrar(pokemon);
        mostrarInfo(pokemon);
        cout << "---------------------------------------------------------------" << endl;
    }
}
