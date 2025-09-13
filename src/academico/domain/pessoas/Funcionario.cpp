#include "academico/domain/pessoas/Funcionario.hpp"
#include "utils/string_utils.hpp"

#include <iostream>
#include <cstdint>

/**
 * @brief Construtora
 */
Funcionario::Funcionario(uint16_t id,
    const char* nome,
    const char* cpf,
    double salario
) : Pessoa(id, nome, cpf),
    m_salario(salario)
{}

/**
 * @brief Devolve o salário
 * @return m_salario double
 */
double Funcionario::get_salario() const
{
    return m_salario;
}

/**
 * @brief Função virtual de exibir
 */
void Funcionario::exibir_detalhes() const
{
    std::cout << "--- Detalhes do Funcionario ---" << std::endl;
    std::cout << "ID: " << m_id << std::endl;
    std::cout << "Nome: " << m_nome << std::endl;
    std::cout << "CPF: " << m_cpf << std::endl;
    std::cout << "Salario:" << m_salario << std::endl;
    std::cout << "-------------------------" << std::endl;
}
