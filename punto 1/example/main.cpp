#include "../include/pokedex.h"

using namespace std;


int main(){
    //Creacion de la Pokedex
    Pokedex pokedexMap1("../pokedexMapTest");

    //Creacion de Pokemones;
    Pokemon squirtle = Pokemon("Squirtle", 100);
    Pokemon bulbasaur = Pokemon("Bulbasaur", 270);
    Pokemon charmander = Pokemon("Charmander", 633);

    //Creacion ataques por nivel - Pokemones
    map<string, int> ataquesPorNivelSquirtle = {{"Pistola Agua", 4}, {"Hidrobomba", 6}, {"Danza Lluvia", 5}};
    map<string, int> ataquesPorNivelBulbasaur = {{"Latigazo", 4}, {"Hoja Afilada", 6}, {"Rayo Solar", 5}};
    map<string, int> ataquesPorNivelCharmander = {{"Ascuas", 4}, {"Lanzallamas", 6}, {"Giro Fuego", 5}};

    //Creacion experiencia por nivel - Pokemones
    vector<int> experienciaNivelSquirtle = {0, 400, 1000};
    vector<int> experienciaNivelBulbasaur = {0, 300, 1100};
    vector<int> experienciaNivelCharmander =  {0, 250, 1300};

    PokemonInfo squirtleInfo = PokemonInfo("Agua", "Una tortuga pequeña que lanza chorros de agua", ataquesPorNivelSquirtle, experienciaNivelSquirtle);
    PokemonInfo bulbasaurInfo = PokemonInfo("Planta", "Tiene una semilla en su lomo que crece con el tiempo", ataquesPorNivelBulbasaur, experienciaNivelBulbasaur);
    PokemonInfo charmanderInfo = PokemonInfo("Fuego", "Una lagartija con una llama en su cola", ataquesPorNivelCharmander, experienciaNivelCharmander);

    //Archivo de serializacion
    //ofstream out("pokedexMapTest", ios:: binary); LO COMENTE PQ NO ES NECESARIO

    //Agregado de los Pokemones con su informacion al mapa Pokedex, cada uno serializa
    pokedexMap1.agregarPokemon(squirtle, squirtleInfo);
    pokedexMap1.agregarPokemon(bulbasaur, bulbasaurInfo);
    pokedexMap1.agregarPokemon(charmander, charmanderInfo);

    //Serializacion
    //if (out.is_open()){
        //pokedexMap1.serializar(); ESTO TAMPOCO
        //out.close();
    //}

    //Archivo de deserializacion
    Pokedex pokedexCargada("../pokedexMapTest")
    //ifstream in("pokedexMapTest", ios:: binary);
    //Deserializacion
    //if (in.is_open()){
        //pokedexCargada.deserializar();
        //in.close();
    pokedexCargada.mostrarTodos();
    return 0;
}
