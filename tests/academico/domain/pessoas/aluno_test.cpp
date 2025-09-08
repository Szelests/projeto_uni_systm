#include "CppUTest/TestHarness.h"

// C++ Moderno
#include <memory>  // Para std::unique_ptr e std::make_unique
#include <utility> // Para std::move

// Inclui a definição do Aluno e a INTERFACE da qual o histórico depende
#include "academico/domain/pessoas/Aluno.hpp"
#include "academico/domain/IHistoricoAcademico.hpp"

// Inclui o nosso MOCK, que também implementa a interface
#include "academico/domain/mocks/HistoricoAcademicoMock.hpp"


TEST_GROUP(TesteAluno)
{
    Aluno* aluno;

    // O setup agora cria o mock e o injeta no Aluno
    void setup() {
        // 1. Cria uma instância do nosso histórico FALSO (mock)
        auto historico_mock = std::make_unique<HistoricoAcademicoMock>();
        
        // 2. Cria o Aluno, passando a posse do mock para ele.
        //    O Aluno agora depende da interface, não da classe concreta.
        aluno = new Aluno(
            101, 
            "Joana d Arc", 
            "222.333.444-55", 
            "2025-123", 
            501, 
            std::move(historico_mock)
        );
    }

    void teardown() {
        delete aluno;
    }
};

// Teste 1: Verifica o construtor e os getters básicos
// Este teste continua igual e deve funcionar perfeitamente.
TEST(TesteAluno, ConstrutorInicializaCorretamenteOsAtributos)
{
    CHECK_EQUAL(101, aluno->get_id());
    STRCMP_EQUAL("Joana d Arc", aluno->get_nome());
    STRCMP_EQUAL("222.333.444-55", aluno->get_cpf());
    STRCMP_EQUAL("2025-123", aluno->get_matricula());
    CHECK_EQUAL(501, aluno->get_curso_id());
}

// Teste 2: Verifica o truncamento da matrícula
// Este teste também continua válido, mas precisamos recriar o Aluno
// passando um novo mock.
TEST(TesteAluno, MatriculaLongaDeveSerTruncada)
{
    // ARRANGE: Como este teste precisa de um Aluno diferente,
    // liberamos o do setup e criamos um novo.
    delete aluno;
    auto historico_mock = std::make_unique<HistoricoAcademicoMock>();
    aluno = new Aluno(102, "Maria", "111", "MATRICULA-MUITO-LONGA", 502, std::move(historico_mock));

    // ASSERT
    STRCMP_EQUAL("MATRICULA", aluno->get_matricula());
}

// Teste 3: Verifica se o método set_curso_id funciona
TEST(TesteAluno, SetCursoIdAlteraOCursoCorretamente)
{
    // ACT
    aluno->set_curso_id(999);

    // ASSERT
    CHECK_EQUAL(999, aluno->get_curso_id());
}

// Teste 4: Verifica se Aluno se comunica corretamente com o Histórico (Mock)
// Agora este teste é mais complexo e robusto.
TEST(TesteAluno, AdicionarNotaDelegaCorretamenteParaHistorico)
{
    // ARRANGE
    uint16_t id_disciplina = 601;
    double valor_nota = 9.5;

    // Precisamos de acesso ao mock para verificar seu estado depois.
    // Primeiro, pegamos o ponteiro para a interface IHistoricoAcademico.
    // É necessário um getter para m_historico na classe Aluno.
    // Supondo que você adicionou:
    // const IHistoricoAcademico* get_historico_ptr() const { return m_historico.get(); }
    
    // Como estamos no teste, faremos um cast para ter acesso aos membros do mock.
    // CUIDADO: Este tipo de cast só é seguro porque SABEMOS que injetamos um mock.
    HistoricoAcademicoMock* hist_mock = dynamic_cast<HistoricoAcademicoMock*>(aluno->get_historico_ptr());

    // ACT
    aluno->adicionar_nota(id_disciplina, valor_nota);

    // ASSERT
    // Verificamos o estado do mock para confirmar que o método foi chamado corretamente.
    CHECK_TRUE(hist_mock->add_nota_foi_chamado);
    CHECK_EQUAL(id_disciplina, hist_mock->ultimo_id_disciplina_recebido);
    DOUBLES_EQUAL(valor_nota, hist_mock->ultima_nota_recebida, 0.001);
}