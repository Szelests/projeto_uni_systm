#include "CppUTest/TestHarness.h"
#include "utils/Lista.hpp"
#include <stdexcept> // Para std::out_of_range

TEST_GROUP(TesteLista)
{
    // Usaremos um ponteiro para poder recriá-lo facilmente em cada teste
    Lista<int>* lista_int;

    void setup() {
        lista_int = new Lista<int>();
    }
    void teardown() {
        delete lista_int;
    }
};

// Teste 1: Verifica o estado de uma lista recém-criada
TEST(TesteLista, ConstrutorPadraoCriaListaVazia)
{
    CHECK_EQUAL(0, lista_int->get_tamanho());
    CHECK_EQUAL(0, lista_int->get_capacidade());
    CHECK_TRUE(lista_int->esta_vazia());
}

// Teste 2: Verifica a adição de elementos e o tamanho
TEST(TesteLista, AdicionarIncrementaTamanhoEGuardaElemento)
{
    lista_int->adicionar(10);
    lista_int->adicionar(20);

    CHECK_EQUAL(2, lista_int->get_tamanho());
    CHECK_FALSE(lista_int->esta_vazia());
    CHECK_EQUAL(10, (*lista_int)[0]); // Usa o operator[] para verificar
    CHECK_EQUAL(20, (*lista_int)[1]);
}

// Teste 3: Verifica se o redimensionamento automático funciona
TEST(TesteLista, RedimensionaAutomaticamenteQuandoCapacidadeExcedida)
{
    // A primeira adição define a capacidade para 10
    for (int i = 0; i < 11; ++i) {
        lista_int->adicionar(i);
    }

    CHECK_EQUAL(11, lista_int->get_tamanho());
    CHECK_EQUAL(20, lista_int->get_capacidade()); // Capacidade deve ter dobrado para 20
    CHECK_EQUAL(10, (*lista_int)[10]); // Verifica se o último elemento está correto
}

// Teste 4: Verifica a remoção de um elemento
TEST(TesteLista, RemoverDiminuiTamanhoEDeslocaElementos)
{
    lista_int->adicionar(10);
    lista_int->adicionar(20);
    lista_int->adicionar(30);
    lista_int->adicionar(40);

    lista_int->remover(1); // Remove o elemento "20" no índice 1

    CHECK_EQUAL(3, lista_int->get_tamanho());
    CHECK_EQUAL(10, (*lista_int)[0]);
    CHECK_EQUAL(30, (*lista_int)[1]); // O elemento "30" deve ter se movido para o índice 1
    CHECK_EQUAL(40, (*lista_int)[2]);
}

// Teste 5: Verifica a "Regra dos Três" - Construtor de Cópia
TEST(TesteLista, ConstrutorDeCopiaCriaCopiaProfunda)
{
    // ARRANGE
    lista_int->adicionar(10);
    lista_int->adicionar(20);

    // ACT
    Lista<int> copia = *lista_int; // Chama o construtor de cópia

    // ASSERT
    CHECK_EQUAL(2, copia.get_tamanho());
    CHECK_EQUAL(10, copia[0]);

    // **Teste de Cópia Profunda**: Modificar a cópia não deve afetar o original
    copia[0] = 99;
    CHECK_EQUAL(99, copia[0]);
    CHECK_EQUAL(10, (*lista_int)[0]); // O original deve permanecer inalterado
}

// Teste 6: Verifica a "Regra dos Três" - Operador de Atribuição
TEST(TesteLista, OperadorDeAtribuicaoCriaCopiaProfunda)
{
    // ARRANGE
    lista_int->adicionar(10);
    lista_int->adicionar(20);
    Lista<int> outra_lista;
    outra_lista.adicionar(99);

    // ACT
    outra_lista = *lista_int; // Chama o operator=

    // ASSERT
    CHECK_EQUAL(2, outra_lista.get_tamanho());

    // **Teste de Cópia Profunda**: Modificar a nova lista não deve afetar a original
    outra_lista[0] = 111;
    CHECK_EQUAL(111, outra_lista[0]);
    CHECK_EQUAL(10, (*lista_int)[0]); // O original deve permanecer inalterado
}

// Teste 7: Verifica o tratamento de erros para acesso fora dos limites
TEST(TesteLista, LancaExcecaoParaAcessoForaDoLimite)
{
    lista_int->adicionar(10);
    
    // CppUTest usa uma macro especial para verificar se uma exceção é lançada
    CHECK_THROWS(std::out_of_range, (*lista_int)[5]);
    CHECK_THROWS(std::out_of_range, lista_int->remover(5));
}