#include "academico/domain/Nota.hpp"

Nota::Nota(uint16_t disciplina_id, double valor)
    : m_disciplina_id(disciplina_id), m_valor(valor)
{
    // A lista de inicialização já fez todo o trabalho.
    // Poderíamos adicionar validações aqui, ex: if(valor < 0 || valor > 10) ...
}

uint16_t Nota::get_disciplina_id() const {
    return m_disciplina_id;
}

double Nota::get_valor() const {
    return m_valor;
}