#include "Cliente.h"

/// Criando a classe cliente
Cliente::Cliente(string nome, string cpf) {
    this->nome = nome;
    this->cpf = cpf;
}

/// Metodos getters para acesasr os atributos privados
string Cliente::getNome() const {
    return nome;
}

string Cliente::getCpf() const {
    return cpf;
}
