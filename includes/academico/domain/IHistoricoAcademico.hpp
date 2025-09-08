#ifndef __I_HISTORICO_ACADEMICO_HPP__
#define __I_HISTORICO_ACADEMICO_HPP__

#include "Nota.hpp" // Inclui a definição da nossa nova classe Nota

// A "Tomada de Parede"
class IHistoricoAcademico {
public:
    virtual ~IHistoricoAcademico() {}

    // O "Contrato" agora usa a classe Nota externa
    virtual void adicionar_nota(const Nota& nota) = 0;
    
    // Outros métodos do contrato
    virtual double calcular_cr() const = 0;
};

#endif // __I_HISTORICO_ACADEMICO_HPP__