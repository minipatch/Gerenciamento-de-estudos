#ifndef PESSOA_HPP
#define PESSOA_HPP

#include "vector.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include "Materia.hpp"
#include "sstream"


class Pessoa{
    private:
        std::string _nome;

        int _idade;
        int _contador;

        std::string login;
        std::string senha;


        vector _v1;
    public:

        Pessoa();

        void Cadastro(std::string nome,int idade,int contador,vector& v,std::string login,std::string senha);

        void verInformacao();

        bool arquivoContemCabecalho(const std::string &nomeArquivo);

};



#endif



