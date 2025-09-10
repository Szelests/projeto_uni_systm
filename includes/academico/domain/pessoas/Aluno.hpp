#ifndef __ALUNO_HPP__
#define __ALUNO_HPP__

#include <memory>  // Para std::unique_ptr
#include <cstdint>
#include "Pessoa.hpp"
#include "academico/domain/IHistoricoAcademico.hpp"

#define TAMANHO_MAX_MATRICULA 10

class Aluno : virtual public Pessoa 
{
private:
    char m_matricula[TAMANHO_MAX_MATRICULA];
    uint16_t m_curso_id;
    // O histórico agora é um ponteiro inteligente para a INTERFACE
    std::unique_ptr<IHistoricoAcademico> m_historico;

public:
    // O construtor agora aceita o ponteiro inteligente
    Aluno(
        uint32_t id, 
        const char* nome, 
        const char* cpf, 
        const char* matricula, 
        uint16_t curso_id,
        std::unique_ptr<IHistoricoAcademico> historico
    );

    const char* get_matricula() const;
    uint16_t get_curso_id() const;
    void set_curso_id(uint16_t id);
    
    void adicionar_nota(uint16_t disciplina_id, double valor);
    

    const IHistoricoAcademico* get_historico_ptr() const { return m_historico.get(); }
    IHistoricoAcademico* get_historico_ptr() { return m_historico.get(); }


    void exibir_detalhes() const override; 
};

#endif // __ALUNO_HPP__