#ifndef __ALUNO_MONITOR_HPP__
#define __ALUNO_MONITOR_HPP__

#include "Aluno.hpp"
#include "Funcionario.hpp"

// Herda de Aluno E de Funcionario
class AlunoMonitor : public Aluno, public Funcionario
{
private:
    uint16_t m_disciplinaMonitoriaId;

public:
    AlunoMonitor(
        uint16_t id,
        const char* nome,
        const char* cpf,
        const char* matricula,
        uint16_t cursoId,
        const char* id_funcional,
        uint32_t salario,
        uint16_t disciplina_monitoria_id
    );

    void exibir_detalhes() const override;
};

#endif // __ALUNO_MONITOR_HPP__