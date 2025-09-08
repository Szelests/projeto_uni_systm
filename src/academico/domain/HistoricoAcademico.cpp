#include "academico/domain/HistoricoAcademico.hpp"

void HistoricoAcademico::adicionar_nota(const Nota& nota)
{
    // Procura se já existe uma nota para esta disciplina
    for (size_t i = 0; i < m_notas.get_tamanho(); ++i) {
        // CORRIGIDO: Usa o operador[] em vez de obter()
        if (m_notas[i].get_disciplina_id() == nota.get_disciplina_id()) {
            // Se encontrou, atualiza a nota existente e termina a função
            m_notas[i] = nota;
            return;
        }
    }

    // Se o loop terminou e não encontrou, adiciona a nova nota
    m_notas.adicionar(nota);
}

Nota* HistoricoAcademico::get_nota_por_disciplina(uint16_t disciplina_id)
{
    for (size_t i = 0; i < m_notas.get_tamanho(); ++i) {
        // CORRIGIDO: Usa o operador[] em vez de obter()
        if (m_notas[i].get_disciplina_id() == disciplina_id) {
            return &m_notas[i];
        }
    }
    
    return nullptr;
}

const Nota* HistoricoAcademico::get_nota_por_disciplina(uint16_t disciplina_id) const
{
    for (size_t i = 0; i < m_notas.get_tamanho(); ++i) {
        // CORRIGIDO: Usa o operador[] em vez de obter()
        if (m_notas[i].get_disciplina_id() == disciplina_id) {
            return &m_notas[i];
        }
    }
    return nullptr;
}

double HistoricoAcademico::calcular_cr() const
{
    if (m_notas.esta_vazia()) { // Usando o novo método esta_vazia()
        return 0.0;
    }

    double soma_das_notas = 0.0;
    for (size_t i = 0; i < m_notas.get_tamanho(); ++i) {
        // CORRIGIDO: Usa o operador[] em vez de obter()
        soma_das_notas += m_notas[i].get_valor();
    }

    return soma_das_notas / m_notas.get_tamanho();
}