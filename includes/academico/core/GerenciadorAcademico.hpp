#ifndef __GERENCIADOR_ACADEMICO_HPP__
#define __GERENCIADOR_ACADEMICO_HPP__

#include <cstdint>
#include <stdexcept>
#include <iostream>
#include <cstring>

#include "../includes\utils\Lista.hpp"
#include "../domain/Departamento.hpp"
#include "../domain/Curso.hpp"
#include "../domain/Disciplina.hpp"
#include "../domain/Turma.hpp"


class GerenciadorAcademico 
{
    private:
        Lista<Departamento> m_departamentos;
        Lista<Curso> m_cursos;
        Lista<Disciplina> m_disciplinas;
        Lista<Turma> m_turmas;
        uint16_t m_proximo_id_academico;

    public:
        // --- create methods ---
        Departamento& criar_departamento();
        Curso& criar_curso();
        Disciplina& criar_disciplina();
        
        // --- get methods ---
        Departamento& get_departamento_por_id(uint16_t id);
        Curso& get_curso_por_id(uint16_t id);
        Disciplina& get_disciplina_por_id(uint16_t id); 

};

#endif //__GERENCIADOR_ACADEMICO_HPP__