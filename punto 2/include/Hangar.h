#pragma once

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std; 

class Hangar{
    private:
        static const int CANTDRONES = 5;
        //Mutex para controlar el acceso a las posiciones de los drones
        mutex posiciones[CANTDRONES]; 
        //Vector de threads (drones)
        vector<thread> drones;
        //Mutex para habilitar el acceso a la consola
        mutex habilitado;
    public:
        //Constructor
        Hangar() = default;
        
        //Métodos
        void despegar(int dron);
        void simularDespegues(); 
        
        //Destructor
        ~Hangar() = default;

};