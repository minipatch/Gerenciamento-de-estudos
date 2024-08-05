#ifndef MATERIA_HPP
#define MATERIA_HPP


#include <iostream>
#include <string>   
#include <vector>


class Materia{
    private:
        std::string Nome;
    
        int Minutos;

    public:

        Materia();

        void setMinutos(int minutos);

        void setNome(std::string nome);

        std::string getNome();

        int getMinutos();


};



#endif 