#include "academico/domain/pessoas/Pessoa.hpp"

/**
 * @brief Construtrora
 * @param id uint16_t
 * @param name const char*
 * @param cpf const char*
 */
Pessoa::Pessoa(uint16_t id, const char* nome, const char* cpf)
: m_id(id)
{
    // Assignação do nome
    if(nome) 
    {
        strncpy(m_nome, nome, TAMANHO_MAX_NOME - 1);
        
        m_nome[TAMANHO_MAX_NOME - 1] = '\0';
    } else 
    {
        m_nome[0] = '\0';
    }

    // Assignação de CPF
    if(cpf) 
    {
        strncpy(m_cpf, cpf, TAMANHO_MAX_CPF - 1);

        m_cpf[TAMANHO_MAX_CPF - 1] = '\0';
    } else 
    {
        m_cpf[0] = '\0';
    }
}

/**
 * @brief Retorna o ID de entidade Pessoa ou derivados
 * @return id uint16_t
 */
uint16_t Pessoa::get_id() const 
{
    return m_id;
}

/**
 * @brief Retorna o ponteiro para nome
 * @return nome const char*
 */
const char* Pessoa::get_nome() const
{
    return m_nome;
}

/**
 * @brief Retorna o ponteiro para cpf
 * @return cpf const char*
 */
const char* Pessoa::get_cpf() const 
{
    return m_cpf;
}



