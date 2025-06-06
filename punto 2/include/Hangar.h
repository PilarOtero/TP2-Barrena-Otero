#pragma once

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
using namespace std; 

class Hangar{
    public:
        Hangar() = default;
        void despegar(int dron);
        void simularDespegues() const; // ver dsps si es const
        ~Hangar() = default;
    private:
        static const int CANTDRONES = 5;
        mutex posiciones[CANTDRONES]; 
        vector<thread> drones;
        mutex habilitado;
};