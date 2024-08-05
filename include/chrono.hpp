#ifndef CHRONO_HPP
#define CHRONO_HPP

#include <iostream>
#include <string>
#include <thread>
#include <iomanip>
#include <chrono>

namespace chr
{

    class Chrono
    {
    private:
    std::chrono::time_point<std::chrono::high_resolution_clock> _startTime;
    std::chrono::duration<int> _duration;
    bool _runing;
    int _minutos;
    int _segundos;

    public:
        Chrono();

        void configurarTempo(int minutos);

        void iniciar();

        void parar();

        void exibir();

        void atualizar();

        int getMinutos();
        int getSegundos();
    };

}

#endif