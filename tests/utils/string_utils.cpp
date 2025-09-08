#include "CppUTest/TestHarness.h"
#include "utils/string_utils.hpp"

// --- Grupo de Testes para a Biblioteca StringUtils (versão modificada) ---
TEST_GROUP(StringUtilsModifiedTest)
{
    // Não precisamos de setup/teardown para testar funções puras.
};

// --- Testes para a função trim() ---
TEST(StringUtilsModifiedTest, TrimRetornaBooleanoCorreto)
{
    // Cenário 1: String é modificada
    char str1[] = "   ola mundo   ";
    bool foi_modificada = StringUtils::trim(str1);
    CHECK_TRUE(foi_modificada);
    STRCMP_EQUAL("ola mundo", str1);

    // Cenário 2: String NÃO é modificada
    char str2[] = "ola mundo";
    bool nao_foi_modificada = StringUtils::trim(str2);
    CHECK_FALSE(nao_foi_modificada);
    STRCMP_EQUAL("ola mundo", str2);

    // Cenário 3: String vazia não é modificada
    char str3[] = "";
    CHECK_FALSE(StringUtils::trim(str3));
    STRCMP_EQUAL("", str3);
}

// --- Testes para a função reduce_internal_spaces() ---
TEST(StringUtilsModifiedTest, ReduceSpacesRetornaBooleanoCorreto)
{
    // Cenário 1: String é modificada
    char str1[] = "Ola      Mundo";
    CHECK_TRUE(StringUtils::reduce_internal_spaces(str1));
    STRCMP_EQUAL("Ola Mundo", str1);

    // Cenário 2: String NÃO é modificada
    char str2[] = "Ola Mundo";
    CHECK_FALSE(StringUtils::reduce_internal_spaces(str2));
    STRCMP_EQUAL("Ola Mundo", str2);
}

// --- Testes para a função remove_all_spaces() ---
TEST(StringUtilsModifiedTest, RemoveAllSpacesRetornaBooleanoCorreto)
{
    // Cenário 1: String é modificada
    char str1[] = " O l a   M u n d o ";
    CHECK_TRUE(StringUtils::remove_all_spaces(str1));
    STRCMP_EQUAL("OlaMundo", str1);

    // Cenário 2: String NÃO é modificada
    char str2[] = "OlaMundo";
    CHECK_FALSE(StringUtils::remove_all_spaces(str2));
    STRCMP_EQUAL("OlaMundo", str2);
}