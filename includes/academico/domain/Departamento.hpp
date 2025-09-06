#ifndef __DEPARTAMENTO_HPP__
#define __DEPARTAMENTO_HPP__

#include <cstdint>
#include <iostream>
#include <cstring>

#include "../includes\utils\Lista.hpp"

class Departamento
{
    private:
        uint16_t m_id;
        char m_name[20];
        char m_sigla[10];
        Lista<uint16_t> m_professores_ids;
        Lista<uint16_t> m_cursos_ids;

    public:
        uint16_t get_id() const;
        const char* get_nome();
        void adicionar_professor(uint16_t professor_id);
        const Lista<uint16_t>& get_professores_ids() const;
        void adicionar_curso_id(uint16_t curso_id);
        const Lista<uint16_t>& get_cursos_ids() const;
};

#endif // __DEPARTAMENTO_HPP__