#ifndef __HISTORICO_ACADEMICO_MOCK_HPP__
#define __HISTORICO_ACADEMICO_MOCK_HPP__

#include "academico/domain/IHistoricoAcademico.hpp" // 1. Inclui a interface!
#include "academico/domain/Nota.hpp"                 // 2. Inclui a classe Nota real!

// 3. O nome da classe é explícito e herda da interface
class HistoricoAcademicoMock : public IHistoricoAcademico {
public:
    // Atributos "espiões" para o teste
    bool add_nota_foi_chamado;
    uint16_t ultimo_id_disciplina_recebido;
    double ultima_nota_recebida;

    // Construtor do mock para inicializar os valores
    HistoricoAcademicoMock() 
        : add_nota_foi_chamado(false), 
          ultimo_id_disciplina_recebido(0), 
          ultima_nota_recebida(0.0)
    {}

    // O destrutor virtual da interface é sobrescrito automaticamente.

    // 4. Cumprindo o contrato da interface com a assinatura correta e "override"
    void adicionar_nota(const Nota& nota) override {
        this->add_nota_foi_chamado = true;
        
        // 5. Agora podemos acessar os dados da Nota real para testes mais precisos
        this->ultimo_id_disciplina_recebido = nota.get_disciplina_id();
        this->ultima_nota_recebida = nota.get_valor();
    }

    double calcular_cr() const override {
        // Para um mock, podemos retornar um valor fixo e previsível.
        // Isso é útil se algum teste futuro precisar deste valor.
        return 7.5; 
    }
};

#endif // __HISTORICO_ACADEMICO_MOCK_HPP__