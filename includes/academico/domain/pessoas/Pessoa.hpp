#ifndef __PESSOA_HPP__
#define __PESSOA_HPP

#include <cstdint>
#include <cstring>
#include <iostream>

#define TAMANHO_MAX_NOME 30
#define TAMANHO_MAX_CPF 15 

class Pessoa 
{
    protected:
        uint16_t m_id;
        char m_nome[TAMANHO_MAX_NOME];
        char m_cpf[TAMANHO_MAX_CPF];

    public:
        Pessoa(uint16_t id, const char* nome, const char* cpf);

        virtual ~Pessoa() {} 

        uint16_t get_id() const;
        const char* get_nome() const;
        const char* get_cpf() const;

        // Só tem implementação nas classes filhas
        virtual void exibir_detalhes() const = 0;
};

#endif // __PESSOA_HPP__