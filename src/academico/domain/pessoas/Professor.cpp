#include "academico/domain/pessoas/Professor.hpp"
#include "utils/string_utils.hpp"

#include <iostream>
#include <cstdint>

/**
 * @brief Construtora
 */
Professor::Professor(uint16_t id, 
    const char* nome,
    const char* cpf,
    double salario,
    uint16_t departamento_id
) : Funcionario(id, nome, cpf, salario),
    m_departamento_id(departamento_id)
{}

/**
 * @brief Get do id do departamento do qual o professor está presente
 * @return m_departamento_id uint16_t
 */
uint16_t Professor::get_departamento_id()
{
    return m_departamento_id;
}

/**
 * @brief Get da referência da lista de is das disciplinas lecionadas
 * @return m_disciplinas_lecionadas_ids Lista<uint16_t>&
 */
const Lista<uint16_t>& Professor::get_disciplinas_lecionadas_id() const 
{
    return m_disciplinas_lecionadas_ids;
}

/**
 * @brief Set de um novo departamento id para o professor
 * @param novo_id uint16_t
 */
void Professor::set_departamento_id(uint16_t novo_id)
{
    if(novo_id) m_departamento_id = novo_id;
}

/**
 * @brief Adiciona uma disciplina ao professor
 * @param disciplina_id uint16_t
 */
void Professor::adicionar_disciplina_lecionada(uint16_t disciplina_id)
{
    if(disciplina_id) m_disciplinas_lecionadas_ids.adicionar(disciplina_id);
}

void Professor::exibir_detalhes() const 
{
    std::cout << "--- Detalhes do Professor ---" << std::endl;
    std::cout << "ID: " << m_id << std::endl;
    std::cout << "Nome: " << m_nome << std::endl;
    std::cout << "CPF: " << m_cpf << std::endl;
    std::cout << "Salario:" << m_salario << std::endl;
    std::cout << "-------------------------" << std::endl;
}