#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "Materia.hpp"

class vector
{

private:
    int _tamanho;
    int _atual;
    Materia *_vector;

public:
    vector();

    vector(int tamanho);

    ~vector();

    void adicionar(Materia a);

    Materia remover();

    int getAtual();

    Materia removepos(int i);

    //    bool vazio();

    //    bool cheio();
};

#endif