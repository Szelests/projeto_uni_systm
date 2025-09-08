#ifndef __HISTORICO_ACADEMICO_HPP__
#define __HISTORICO_ACADEMICO_HPP__

#include <cstdint>
#include <iostream>

#include "utils/Lista.hpp"
#include "academico/domain/IHistoricoAcademico.hpp"
#include "academico/domain/Nota.hpp" // Incluindo a definição de Nota

class HistoricoAcademico : public IHistoricoAcademico
{
private:
    Lista<Nota> m_notas;

public:
    // Construtor padrão é suficiente
    HistoricoAcademico() = default;

    // Métodos do "contrato" da interface
    void adicionar_nota(const Nota& nota) override;
    
    // Métodos específicos desta implementação
    Nota* get_nota_por_disciplina(uint16_t disciplina_id);
    const Nota* get_nota_por_disciplina(uint16_t disciplina_id) const; // Versão const
    double calcular_cr() const;
};

#endif // __HISTORICO_ACADEMICO_HPP__