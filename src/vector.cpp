#include "vector.hpp"

vector::vector(){}


vector::vector(int tamanho){
    this->_tamanho = tamanho;
    this->_atual = -1;

    _vector = new Materia[_tamanho];
}



vector::~vector(){
    delete[] _vector;
}


void vector::adicionar(Materia a){
    if(_atual == _tamanho){
        std::cout<<"a fila esta cheia"<< std::endl;
        return;
    }
    _vector[++_atual] = a;

}



Materia vector::remover(){
    Materia aux1;

    if(_atual == -1){
        std::cout<<"a fila esta vazia"<<std::endl;
        return aux1;
    }
    Materia aux = _vector[_atual];

    _atual--;

    return aux;
}

int vector::getAtual(){
    return _atual;
}
