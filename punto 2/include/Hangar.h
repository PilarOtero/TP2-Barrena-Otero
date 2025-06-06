#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
using namespace std; 

class Hangar{
    public:
        Hangar() = default;
        void despegar();
        void simularDespegues(int dron) const; // ver dsps si es const
        void logMessage(const string& mensaje);
        ~Hangar() = default;
    private:
        static const int CANTDRONES = 5;
        mutex posiciones[CANTDRONES]; 
        vector<thread> drones;
};