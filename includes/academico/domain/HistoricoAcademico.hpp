#ifndef __HISTORICO_ACADEMICO_HPP__
#define __HISTORICO_ACADEMICO_HPP__

#include <cstdint>
#include <iostream>

#include "../includes\utils\Lista.hpp"

class HistoricoAcademico
{
    private:
        typedef struct Nota
        {
            uint16_t m_disciplina_id;
            uint16_t m_valor;
        } Nota;

        Lista<Nota> m_notas;
    public:
        void adicionarNota(const Nota& nota);
        void getNotaPorDisciplina(uint16_t disciplina_id);
        uint16_t calcular_CR();
};



#endif // __HISTORICO_ACADEMICO_HPP__
