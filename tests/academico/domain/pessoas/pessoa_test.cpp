// Inclui o cabeçalho principal do CppUTest para ter acesso às macros de teste
#include "CppUTest/TestHarness.h"

// Inclui a classe que queremos testar.
// Usamos o caminho a partir da pasta 'include', como configurado no CMake.
#include "academico/domain/pessoas/Pessoa.hpp"

// --- Classe de Teste (Test Double) ---
// Como a classe Pessoa é abstrata (por causa de exibir_detalhes() = 0),
// não podemos criar um objeto "new Pessoa()". Para testar a lógica que
// existe em Pessoa, nós criamos uma classe filha mínima e concreta.
class PessoaParaTeste : public Pessoa {
public:
    // O construtor dela simplesmente repassa os dados para o construtor de Pessoa
    PessoaParaTeste(uint32_t id, const char* nome, const char* cpf)
        : Pessoa(id, nome, cpf) {}

    // Implementação mínima da função virtual pura, apenas para o teste compilar.
    void exibir_detalhes() const override {
        // Não faz nada, pois não estamos testando este método aqui.
    }
};


// --- Grupo de Testes para a Classe Pessoa ---
TEST_GROUP(TestePessoa)
{
    Pessoa* pessoa; // Ponteiro para a classe base para testar o polimorfismo

    // O método setup() é executado ANTES de cada teste deste grupo
    void setup() {
        pessoa = nullptr; // Boa prática inicializar com nulo
    }

    // O método teardown() é executado DEPOIS de cada teste deste grupo
    void teardown() {
        delete pessoa; // Libera a memória alocada para evitar vazamentos
    }
};

// --- Casos de Teste Específicos ---

// Teste 1: Verifica se o construtor e os getters funcionam com dados normais
TEST(TestePessoa, ConstrutorEGetters)
{
    // ARRANGE: Prepara o objeto para o teste
    pessoa = new PessoaParaTeste(101, "Joao da Silva", "111.222.333-44");

    // ACT & ASSERT: Executa a lógica e verifica o resultado
    CHECK_EQUAL(101, pessoa->get_id());
    STRCMP_EQUAL("Joao da Silva", pessoa->get_nome()); // Use STRCMP_EQUAL para comparar strings C
    STRCMP_EQUAL("111.222.333-44", pessoa->get_cpf());
}

// Teste 2: Verifica se o construtor lida corretamente com nomes muito longos
TEST(TestePessoa, TruncamentoDeStringLonga)
{
    // ARRANGE
    // O nome tem mais de 29 caracteres (o limite do buffer TAMANHO_MAX_NOME)
    pessoa = new PessoaParaTeste(102, "Pedro de Alcantara Francisco Antonio Joao Carlos", "555.666.777-88");
    
    // O construtor seguro com strncpy deve truncar o nome
    const char* nome_esperado = "Pedro de Alcantara Francisco"; // Exatamente 28 caracteres

    // ASSERT
    STRCMP_EQUAL(nome_esperado, pessoa->get_nome());
}

// Teste 3: Verifica se o construtor lida com ponteiros nulos de forma segura
TEST(TestePessoa, TratamentoDePonteiroNulo)
{
    // ARRANGE
    pessoa = new PessoaParaTeste(103, nullptr, nullptr);

    // ASSERT: O construtor deve criar strings vazias, e não quebrar o programa
    STRCMP_EQUAL("", pessoa->get_nome());
    STRCMP_EQUAL("", pessoa->get_cpf());
}