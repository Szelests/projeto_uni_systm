#ifndef __FUNCIONARIO_HPP__
#define __FUNCIONARIO_HPP__

#include "Pessoa.hpp"

class Funcionario : virtual public Pessoa 
{   
    protected:
        double m_salario;

    public:
        Funcionario();
        Funcionario(uint16_t id, const char* nome, const char* cpf, double salario);
        

        double get_salario() const;

        void exibir_detalhes() const override;
};

#endif // __FUNCIONARIO_HPP__