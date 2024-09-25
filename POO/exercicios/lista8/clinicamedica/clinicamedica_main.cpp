#include <iostream>

class Medico {
public:
    std::string nome;
    std::string especialidade;
    std::string crm;

    Medico(const std::string& nome, const std::string& especialidade, const std::string& crm)
        : nome(nome), especialidade(especialidade), crm(crm) {}
};

class Paciente {
public:
    std::string nome;
    std::string cpf;
    std::string data_nascimento;

    Paciente(const std::string& nome, const std::string& cpf, const std::string& data_nascimento)
        : nome(nome), cpf(cpf), data_nascimento(data_nascimento) {}
};

class Consulta {
public:
    std::string data;
    std::string hora;
    Medico* medico;
    Paciente* paciente;

    Consulta(const std::string& data, const std::string& hora, Medico* medico, Paciente* paciente)
        : data(data), hora(hora), medico(medico), paciente(paciente) {}

    void mostrarInformacoes() {
        std::cout << "Consulta agendada para: " << data << " às " << hora << std::endl;
        std::cout << "Médico: " << medico->nome << ", Especialidade: " << medico->especialidade << std::endl;
        std::cout << "Paciente: " << paciente->nome << ", CPF: " << paciente->cpf << std::endl;
    }
};

int main() {
    Medico medico1("Dr. Silva", "Cardiologia", "CRM12345");
    Paciente paciente1("João", "123.456.789-00", "1990-01-01");
    Consulta consulta1("2023-11-13", "15:00", &medico1, &paciente1);
    consulta1.mostrarInformacoes();

    return 0;
}
