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