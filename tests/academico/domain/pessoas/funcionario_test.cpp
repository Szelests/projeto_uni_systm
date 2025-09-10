#include "CppUTest/TestHarness.h"

#include "academico/domain/pessoas/Funcionario.hpp"

TEST_GROUP(TestFuncionario)
{
    Funcionario* funcionario;

    void setup()
    {
        funcionario = new Funcionario(
            101,
            "Joana d Arc",
            "222.333.444-55",
            3000.1
        );
    }

    void teardown()
    {
        delete funcionario;
    }
};

// Test 1: Verifica o construtor e os getters básicos
TEST(TestFuncionario, ConstrutorInicializaCorretamenteOsAtributos)
{
    CHECK_EQUAL(101, funcionario->get_id());
    STRCMP_EQUAL("Joana d Arc", funcionario->get_nome());
    STRCMP_EQUAL("222.333.444-55", funcionario->get_cpf());
    CHECK_EQUAL(3000.1, funcionario->get_salario());
}

