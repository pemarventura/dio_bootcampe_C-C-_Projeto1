#include <iostream>
#include <string>
#include <ctime>
#include <random>
#include <functional>

class Conta {
private:
    double Saldo;

public:
    Conta() {
        Saldo = 1.0;
    }

    void Sacar(double valor) {
        Saldo -= valor;
    }

    void Depositar(double valor){
        Saldo += valor;
    }

    double GetSaldo() const {
        return Saldo;
    }
};

// Wrapper function to intercept Sacar method
void SacarWrapper(Conta& conta, double valor) {
    if (valor > conta.GetSaldo()) {
        std::cout << "Valor de saque maior que o saldo!" << std::endl;
    } else {
        conta.Sacar(valor);
        std::cout << "Conta Saldo" << conta.GetSaldo() << std::endl;
    }
}

class ContaPoupanca : public Conta {
public:
    ContaPoupanca() {
    }
};

class ContaInvestimento : public Conta {
public:
    ContaInvestimento() {
    }
};

int main() {
    const double casoException = 1.1;
    const double casoOk = 0.9;

    // Instantiate a ContaPoupanca object
    ContaPoupanca contaPoupanca;

    // Print the saldo
    SacarWrapper(contaPoupanca, casoException);
   

    // Instantiate a ContaInvestimento object
    ContaInvestimento contaInvestimento;

    SacarWrapper(contaInvestimento, casoOk);

    return 0;
}
