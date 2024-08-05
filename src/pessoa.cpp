#include "pessoa.hpp"

// fazer o cronometro de estudos

Pessoa::Pessoa() {}

bool Pessoa::arquivoContemCabecalho(const std::string &nomeArquivo){
    std::ifstream arquivo(nomeArquivo);
    std::string linha;

    if (!arquivo.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo." << std::endl;
        return false;
    }

    // Verifica se o arquivo está vazio ou se o cabeçalho está presente
    while(std::getline(arquivo,linha)){
        if(linha == "nome,idade,materia,tempo,login,senha"){
            return true;
        }
    }
    return false; // O cabeçalho não está presente
}


void Pessoa::Cadastro(std::string nome, int idade, int contador, vector &v, std::string login, std::string senha) {
    _nome = nome;
    _idade = idade;
    _v1 = v;
    _contador = contador;

    std::cout << "Salvando suas informações: " << std::endl;

    std::ofstream arquivo("dados.csv", std::ios::out | std::ios::app);

    if (!arquivo.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo." << std::endl;
        return;
    }

    // Adiciona o cabeçalho se ainda não estiver presente
    if (!arquivoContemCabecalho("dados.csv")) {
        arquivo << "nome,idade,materia,tempo,login,senha" << std::endl;
    }

    // Adiciona os dados ao arquivo
    for (int i = 0; i < _contador; i++) {
        Materia aux = _v1.remover(); // Assume que v1 é um vetor de Materia
        arquivo << _nome << ','
                << _idade << ','
                << aux.getNome() << ','
                << aux.getMinutos() << ','
                << login << ','
                << senha << std::endl;
    }

    arquivo.close();
}

void Pessoa::verInformacao() {
    std::ifstream arquivo("dados.csv");

    if (!arquivo.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo." << std::endl;
        return;
    }

    std::string linha;
    std::ostringstream conteudo;

    // Ler o cabeçalho do arquivo CSV
    std::getline(arquivo, linha); // Ignorar o cabeçalho

    while (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string campo;

        // Ler e armazenar os campos do CSV
        std::getline(ss, campo, ','); // Nome do estudante
        std::string nome = campo;

        std::getline(ss, campo, ','); // Idade do estudante
        std::string idade = campo;

        std::getline(ss, campo, ','); // Matéria
        std::string materia = campo;

        std::getline(ss, campo, ','); // Tempo
        std::string tempo = campo;

        std::getline(ss, campo, ','); // Login
        std::string loginAtual = campo;

        std::getline(ss, campo); // Senha
        std::string senhaAtual = campo;

        // Máscara login e senha
        if (!loginAtual.empty()) {
            loginAtual = "*******";
        }
        if (!senhaAtual.empty()) {
            senhaAtual = "******";
        }

        // Adicionar informações formatadas ao conteúdo
        conteudo << "Nome: " << nome << std::endl;
        conteudo << "Idade: " << idade << std::endl;
        conteudo << "Matéria: " << materia << ", Tempo: " << tempo << std::endl;
        conteudo << "Login: " << loginAtual << std::endl;
        conteudo << "Senha: " << senhaAtual << std::endl;
        conteudo << std::endl; // Adiciona uma linha em branco entre registros
    }

    arquivo.close();
    std::cout << conteudo.str() << std::endl;
}