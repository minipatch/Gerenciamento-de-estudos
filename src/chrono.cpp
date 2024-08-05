#include <chrono.hpp>

using namespace chr;

Chrono::Chrono() {}

void Chrono::configurarTempo(int minutos)
{
    _duration = std::chrono::seconds(minutos);
}

void Chrono::iniciar()
{
    _startTime = std::chrono::high_resolution_clock::now();
    _runing = true;
}

void Chrono::parar()
{
    _runing = false;
}

void Chrono::exibir()
{
    atualizar();
    std::cout << "\rTempo restante: "
              << std::setw(2) << std::setfill('0') << _minutos << ":"
              << std::setw(2) << std::setfill('0') << _segundos
              << std::flush;
}

void Chrono::atualizar()
{
    if (_runing)
    {
        auto now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<int> elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - _startTime);
        int segundosDecorridos = elapsed.count();
        int segundosRestantes = std::max(0, _duration.count() * 60 - segundosDecorridos);

        _minutos = segundosRestantes / 60;
        _segundos = segundosRestantes % 60;
    }
}

int Chrono::getMinutos()
{
    return _minutos;
}

int Chrono::getSegundos()
{
    return _segundos;
}
