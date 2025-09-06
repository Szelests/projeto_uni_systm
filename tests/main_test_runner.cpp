#include "CppUTest/CommandLineTestRunner.h"

int main(int ac, char** av)
{
    // Roda todos os testes descobertos no projeto e retorna o resultado
    return CommandLineTestRunner::RunAllTests(ac, av);
}