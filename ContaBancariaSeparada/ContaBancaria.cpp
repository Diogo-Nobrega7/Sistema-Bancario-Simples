#include <iostream>
#include "ContaBancaria.h"
using namespace std;

/// Criando a conta bancária
ContaBancaria::ContaBancaria(int numero, Cliente titular, double saldo)
    : numero(numero), titular(titular), saldo(saldo) {}

/// Função para depositar um valor
void ContaBancaria::depositar(double valor, bool mostrarMensagem) {
    if (valor > 0) {
        saldo += valor;
        if (mostrarMensagem) {
            cout << "Deposito de R$" << valor << " efetuado.\n";
        }
    } else {
        cout << "Valor de deposito insuficiente.\n";
    }
}

/// Função para sacar um valor
void ContaBancaria::sacar(double valor) {
    if (valor <= 0) {
        cout << "Valor invalido.\n";
    } else if (valor > saldo) {
        cout << "Saldo de saque insuficiente.\n";
    } else {
        saldo -= valor;
        cout << "Saque de R$" << valor << " efetuado.\n";
    }
}

/// Função para transferir um valor para uma única conta
void ContaBancaria::transferir(double valor, ContaBancaria &destino) {
    if (valor <= 0) {
        cout << "Valor inválido.\n";
    } else if (valor > saldo) {
        cout << "Saldo insuficiente.\n";
    } else {
        saldo -= valor;
        destino.depositar(valor, false);
        cout << "Transferido: R$ " << valor << " da conta " << numero
             << " para a conta " << destino.numero << "\n";
    }
}

/// Função para transferir um valor para multiplas contas
void ContaBancaria::transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2) {
    if (valor <= 0) {
        cout << "Valor inválido.\n";
    } else if (valor > saldo) {
        cout << "Saldo insuficiente.\n";
    } else {
        double metade = valor / 2;
        saldo -= valor;
        destino1.depositar(metade, false);
        destino2.depositar(metade, false);
        cout << "Transferido: R$ " << metade << " para cada conta ("
             << destino1.numero << " e " << destino2.numero << ") da conta " << numero << "\n";
    }
}

/// Exibe o saldo de uma conta
void ContaBancaria::exibirSaldo() const {
    cout << "Saldo atual da conta " << numero << ": R$" << saldo << "\n";
}

/// Exibe informações de uma conta
void ContaBancaria::exibirInformacoes() const {
    cout << "Titular: " << titular.getNome() << ", CPF: " << titular.getCpf() << "\n";
    cout << "Numero da conta: " << numero << ", Saldo: " << saldo << "\n";
}
