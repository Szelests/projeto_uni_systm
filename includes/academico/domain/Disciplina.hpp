#ifndef __DISCIPLINA_HPP__
#define __DISCIPLINA_HPP__

#include <cstdint>
#include <iostream>
#include <cstring>

#include "../includes\utils\Lista.hpp"

class Disciplina
{
    private:
        uint16_t m_id;
        char m_nome[20];
        uint16_t m_creditos;
        Lista<uint16_t> m_prerequisitos;

    public:
        uint16_t get_id() const;
        const char* get_nome() const;
        uint16_t get_creditos() const;
        void adicionar_prerequisito(uint16_t disciplina_id);
        const Lista<uint16_t>& get_prerequisitos_ids(); 

};

#endif // __DISCIPLINA_HPP__