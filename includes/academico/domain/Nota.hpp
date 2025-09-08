#ifndef __NOTA_HPP__
#define __NOTA_HPP__

#include <cstdint>

class Nota {
private:
    uint16_t m_disciplina_id;
    double m_valor;

public:
    // ADICIONADO: Construtor padrão para criar uma "nota vazia"
    Nota() : m_disciplina_id(0), m_valor(0.0) {}

    // Construtor para criar um objeto Nota válido
    Nota(uint16_t disciplina_id, double valor);

    // Getters para acessar os dados de forma segura
    uint16_t get_disciplina_id() const;
    double get_valor() const;
};

#endif // __NOTA_HPP__