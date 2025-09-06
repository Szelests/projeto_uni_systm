#ifndef __CURSO_HPP__
#define __CURSO_HPP__

#include <cstdint>
#include <iostream>
#include <cstring>

#include "../includes\utils\Lista.hpp"

class Curso
{
    private:
        uint16_t m_id;
        char m_nome[20];
        char m_codigo[20];
        uint16_t m_departamento_id;
        Lista<uint16_t> m_grade_curricular_ids;

    public:
        uint16_t get_id() const;
        const char* get_nome();
        uint16_t get_departamento_id() const;
        void adicionar_disciplina_na_grade(uint16_t disciplina_id);
        const Lista<uint16_t>& get_grade_curricular() const;
}; 

#endif // __CURSO_HPP__