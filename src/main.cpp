#include <iostream>
#include <fstream>
#include <string>
#include "vector.hpp"
#include "pessoa.hpp"
#include "chrono.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

bool verificaResposta(const std::string &arquivo, const std::string &login, const std::string &senha)
{
    std::ifstream arquivodeentrada(arquivo);
    std::string linha;

    if (!arquivodeentrada.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return false;
    }

    std::string loginArquivo, senhaArquivo;

    // Ler o arquivo linha por linha
    while (std::getline(arquivodeentrada, linha))
    {
        std::stringstream ss(linha);
        std::string campo;

        // Ler login e senha da linha CSV
        std::getline(ss, campo, ','); // Nome do estudante (ignorado)
        std::getline(ss, campo, ','); // Idade do estudante (ignorado)
        std::getline(ss, campo, ','); // Matéria (ignorado)
        std::getline(ss, campo, ','); // Tempo (ignorado)
        std::getline(ss, loginArquivo, ',');
        std::getline(ss, senhaArquivo);

        // Comparação de login e senha
        if (loginArquivo == login && senhaArquivo == senha)
        {
            std::cout << "Login e senha corretos." << std::endl;
            arquivodeentrada.close();
            return true;
        }
    }

    std::cout << "Login '" << login << "' não encontrado." << std::endl;
    arquivodeentrada.close();
    return false;
}

int buscarTempoPorLoginEDisciplina(const std::string &arquivo, const std::string &loginBuscado, const std::string &disciplinaBuscada)
{
    std::ifstream file(arquivo);
    std::string linha;
    int tempoResult = -1; // Valor padrão indicando que o tempo não foi encontrado

    if (!file.is_open())
    {
        throw std::runtime_error("Não foi possível abrir o arquivo.");
    }

    // Ignorar o cabeçalho
    std::getline(file, linha);

    while (std::getline(file, linha))
    {
        std::stringstream ss(linha);
        std::string nome, idade, materia, tempo, login, senha;

        std::getline(ss, nome, ',');
        std::getline(ss, idade, ',');
        std::getline(ss, materia, ',');
        std::getline(ss, tempo, ',');
        std::getline(ss, login, ',');
        std::getline(ss, senha, ',');

        if (login == loginBuscado && materia == disciplinaBuscada)
        {
            tempoResult = std::stoi(tempo); // Converte o tempo para inteiro
            break;                          // Assumindo que só precisa do primeiro resultado encontrado
        }
    }

    file.close();
    return tempoResult;
}

bool verificaMateria(const std::string &login, const std::string &materia, const std::string &nomeArquivo)
{
    std::ifstream arquivo(nomeArquivo);
    std::string linha;
    std::string loginAtual;
    bool materiaEncontrada = false;

    if (!arquivo.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return false;
    }

    while (std::getline(arquivo, linha))
    {
        std::stringstream ss(linha);
        std::string campo;

        std::getline(ss, campo, ','); // Nome do estudante (ignorado)
        std::getline(ss, campo, ','); // Idade do estudante (ignorado)
        std::getline(ss, campo, ','); // Matéria
        std::string materiaArquivo = campo;
        std::getline(ss, campo, ','); // Tempo (ignorado)
        std::string loginArquivo;
        std::getline(ss, loginArquivo, ','); // Login
        // Senha (ignorada)

        if (loginArquivo == login)
        {
            if (materiaArquivo == materia)
            {
                materiaEncontrada = true;
                break;
            }
        }
    }

    arquivo.close();
    return materiaEncontrada;
}

bool verificaLogin(const std::string& arquivo,std::string login){
    std::ifstream arq(arquivo);
    
    if(!arq.is_open()){
        std::cout<<"arquivo nao encontrado"<<std::endl;
    }

    std::string loginatual;
    std::string linha;

    while(std::getline(arq,linha)){
        std::stringstream ss(linha);

        std::string campo;

        std::getline(ss,campo,',');
        std::getline(ss,campo,',');
        std::getline(ss,campo,',');
        std::getline(ss,campo,',');
        std::getline(ss,campo,',');
        loginatual = campo;
        if(login == loginatual){
            return true;
        }
    }
    return false;
}

std::string RestauraSenha(const std::string& arquivo,std::string login){
    std::ifstream arq(arquivo);

    if(!arq.is_open()){
        std::cerr<<"arquivo nao aberto"<<std::endl;
    }

    std::string linha;
    std::string loginatual;
    std::string senha;

    while(std::getline(arq,linha)){

        std::stringstream ss(linha);
        std::string campo;


        std::getline(ss,campo,',');
        std::getline(ss,campo,',');
        std::getline(ss,campo,',');
        std::getline(ss,campo,',');
        std::getline(ss,campo,',');
        loginatual = campo;
        std::getline(ss,campo,',');
        senha = campo;


        if(loginatual == login){
            break;
        }
    }
    return senha;
}



bool verResposta(const std::string &palavra)
{
    return palavra == "cadastro" || palavra == "login" || palavra == "recuperar conta";
}

int main()
{
    std::cout << "Bem vindo ao gerenciamento de estudos" << std::endl;

    std::cout << "Gostaria de fazer cadastro ou login ou recuperar a conta?" << std::endl;

    std::string palavra;

    while (!verResposta(palavra))
    {
        std::getline(std::cin, palavra);
        if (!verResposta(palavra))
        {
            std::cout << "Opção inválida. Coloque uma opção válida." << std::endl;
        }
    }

    if (palavra == "cadastro")
    {
        std::cout << "insira seu nome: " << std::endl;
        std::string nome;
        std::cin >> nome;
        
        std::cout<<"insira sua idade: "<< std::endl;
        int idade;
        std::cin >> idade;


        std::cout << "Insira um login: " << std::endl;
        std::string login;
        std::cin >> login;

        std::cout << "Insira uma senha: " << std::endl;
        std::string senha, confirmacao;
        std::cin >> senha;

        std::cout << "Insira a senha novamente para confirmar: " << std::endl;

        while (true)
        {
            std::cin >> confirmacao;

            if (senha == confirmacao)
            {
                break;
            }
            else
            {
                std::cout << "Senha de confirmação inválida. Insira novamente." << std::endl;
            }
        }

        Pessoa p;
        std::cout << "Quantas matérias gostaria de fazer?" << std::endl;
        int count;
        std::cin >> count;

        vector v1(count);

        for (int i = 0; i < count; i++)
        {
            std::string aux;
            Materia m1;
            std::cout << "Insira a disciplina número " << i + 1 << std::endl;
            std::cin >> aux;

            int temEstudos;
            std::cout << "Insira o tempo (em minutos) de estudos para a matéria: " << aux << std::endl;
            std::cin >> temEstudos;

            m1.setNome(aux);
            m1.setMinutos(temEstudos);
            v1.adicionar(m1);
        }

        p.Cadastro(nome, idade, count, v1, login, senha);
        return 0;
    }

    else if (palavra == "login")
    {

        int loop = 1;
        std::string login;
        std::string senha;

        while (loop == 1)
        {
            std::cout << "Insira login: " << std::endl;
            std::cin >> login;

            std::cout << "Insira a senha: " << std::endl;
            std::cin >> senha;

            if (verificaResposta("dados.csv", login, senha))
            {
                loop = 0; // Saímos do loop
            }
            else
            {
                std::cout << "Login inválido." << std::endl;
                std::cout << "Gostaria de tentar novamente? (sim/nao)" << std::endl;
                std::string resposta;
                std::cin >> resposta;

                if (resposta == "sim")
                {
                    loop = 1;
                }
                else if (resposta == "nao")
                {
                    return 0;
                }
            }
        }

        bool looploginprincipal = false;
        while (looploginprincipal == false)
        {
            std::cout << "escolha qual materia voce vai estudar? " << std::endl;

            std::string mat;

            int loopaux = 0;

            while (loopaux == 0)
            {
                std::cin >> mat;
                if (verificaMateria(login, mat, "dados.csv"))
                {
                    std::cout << "materia encontrada" << std::endl;
                    loopaux = 1;
                }

                else
                {
                    std::cout << "materia nao encontrada" << std::endl;
                }
            }

            chr::Chrono relogio;
            int tempo = buscarTempoPorLoginEDisciplina("dados.csv", login, mat);

            if (tempo != -1)
            {
                relogio.configurarTempo(tempo);
                relogio.iniciar();

                while (true)
                {
                    relogio.exibir();
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    relogio.atualizar();
                    if (relogio.getMinutos() == 0 && relogio.getSegundos() == 0)
                    {
                        break;
                    }
                }

                relogio.parar();
                std::cout << "\nSeus estudos terminaram" << std::endl;
            }
            else
            {
                std::cout << "Tempo de estudo não encontrado." << std::endl;
            }

            std::cout << "gostaria de estudar uma materia diferente?"<<std::endl;
            std::string resp;

            while(true){
                std::cin>>resp;
                if(resp == "sim"){
                    break;
                }
                else if(resp == "nao"){
                    looploginprincipal = true;
                    break;
                }
                else{
                    std::cout<<"resposta invalida"<<std::endl;
                }
            }
        }
    }

    else if(palavra == "recuperar conta"){
        std::cout<<"insira seu login"<<std::endl;
        std::string login;
        std::string senha;


        while(true){
            std::cin>>login;
            if(verificaLogin("dados.csv",login) == true){
                break;
            }
            else{
                std::cout<<"login invalido"<<std::endl;
            }
        }

        senha = RestauraSenha("dados.csv",login);

        std::cout<<"sua senha e: "<<senha <<std::endl;
    }

    return 0;
}
