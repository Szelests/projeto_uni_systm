#ifndef __PROFESSOR_HPP__
#define __PROGFESSOR_HPP__

#include "Pessoa.hpp"
#include "Funcionario.hpp"
#include "../utils/Lista.hpp"

class Professor : public Funcionario 
{
    private:
        uint16_t m_departamento_id;
        Lista<uint16_t> m_disciplinas_lecionadas;

    public: 
        Professor(
        uint16_t id,                    
        const char* nome,           
        const char* cpf,            
        const char* id_funcional,    
        uint32_t salario,             
        uint16_t departamento_id      
        );

        uint16_t get_departamento_id();
        const Lista<uint16_t>& get_disciplinas_lecionadas_id() const;
        void set_departamento_id(uint16_t novo_id);
        void adicionar_disciplina_lecionada(uint16_t disciplina_id);
        void exibir_detalhes() const override; 
};

#endif // __PROFESSOR_HPP__