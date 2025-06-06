#pragma once

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std; 

class Hangar{
    private:
        static const int CANTDRONES = 5;
        mutex posiciones[CANTDRONES]; 
        vector<thread> drones;
        mutex habilitado;
    public:
        //Constructor
        Hangar() = default;
        
        //Metodos
        void despegar(int dron);
        void simularDespegues(); 
        
        //Destructor
        ~Hangar() = default;

};