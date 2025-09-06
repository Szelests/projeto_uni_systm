#ifndef __TURMA_HPP__
#define __TURMA_HPP__

#include <cstdint>
#include <iostream>
#include <cstring>

#include "../includes\utils\Lista.hpp"

class Turma
{
    private:
        uint32_t m_id;
        uint32_t m_disciplina_id;
        uint32_t m_professor_id;
        char semestre[10];
        uint16_t m_vagas;
        Lista<uint32_t> m_alunos_matriculados;
            
    public:
        bool inscrever_aluno(uint32_t aluno_id);
        uint16_t get_vagas_disponiveis();
};

#endif