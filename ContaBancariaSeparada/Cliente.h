#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
using namespace std;

/// Criando a classe cliente
class Cliente {
private:
    string nome;
    string cpf;

/// Metodos getters para acesasr os atributos privados
public:
    Cliente(string nome, string cpf);
    string getNome() const;
    string getCpf() const;
};

#endif
