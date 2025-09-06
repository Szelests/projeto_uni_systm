#ifndef __ALUNO_HPP__
#define __ALUNO_HPP__

#include "Pessoa.hpp"
#include "../HistoricoAcademico.hpp"

#define TAMANHO_MAX_MATRICULA 10

class Aluno : virtual public Pessoa 
{
    private:
        char m_matricula[10];
        uint16_t m_curso_id;
        HistoricoAcademico m_historico;


    public:
        Aluno(
        uint16_t id,                    
        const char* nome,           
        const char* cpf,            
        const char* m_matricula,    
        uint16_t m_curso_id,
        HistoricoAcademico m_historico
        );

        const char* get_matricula() const;
        uint16_t get_curso_id() const;
        void set_curso_id(uint16_t id);
        void adicionar_nota(uint16_t disciplina_id, uint16_t valor);
        const HistoricoAcademico& get_historico();

        void exibir_detalhes() const override; 
};

#endif // __ALUNO_HPP__