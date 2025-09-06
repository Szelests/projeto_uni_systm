#ifndef __FUNCIONARIO_HPP__
#define __FUNCIONARIO_HPP__

#include "Pessoa.hpp"

class Funcionario : virtual public Pessoa 
{   
    private:
        uint32_t m_salario;

    public:
        Funcionario(uint16_t id, const char* nome, const char* cpf, uint32_t salario);

        void exibir_detalhes() const override;
};

#endif // __FUNCIONARIO_HPP__