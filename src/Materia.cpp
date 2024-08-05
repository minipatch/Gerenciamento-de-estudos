#include "Materia.hpp"


Materia::Materia(){}


void Materia::setNome(std::string nome){
    Nome = nome;
}


std::string Materia::getNome(){
    return Nome;
}

void Materia::setMinutos(int minutos){
    Minutos = minutos;
}

int Materia::getMinutos(){
    return Minutos;
}