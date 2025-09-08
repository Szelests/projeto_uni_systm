# Versão mínima do CMake e nome do projeto
cmake_minimum_required(VERSION 3.10)
project(projeto_uni_systm CXX)

# Define o padrão do C++ (ex: C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- 1. Compila o seu código principal como uma BIBLIOTECA ---
add_library(academico_lib
    # CORE
    src/academico/core/GerenciadorAcademico.cpp
    src/academico/core/GerenciadorDePessoas.cpp
    src/academico/domain/pessoas/Pessoa.cpp
    src/academico/domain/pessoas/Funcionario.cpp
    src/academico/domain/pessoas/Professor.cpp
    src/academico/domain/pessoas/Aluno.cpp
    src/academico/domain/pessoas/AlunoMonitor.cpp 
    src/academico/domain/Curso.cpp
    src/academico/domain/Departamento.cpp
    src/academico/domain/Disciplina.cpp
    src/academico/domain/HistoricoAcademico.cpp
    src/academico/domain/Turma.cpp
    src/academico/domain/Nota.cpp

    # UTILS
    src/utils/string_utils.cpp
)

# Informa ao CMake onde encontrar os cabeçalhos da sua biblioteca (pasta "includes")
target_include_directories(academico_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)

# --- 2. Cria o executável PRINCIPAL do seu sistema ---
add_executable(app_principal src/main.cpp)
target_link_libraries(app_principal PRIVATE academico_lib)


# --- 3. Configuração do CppUTest e dos Testes ---
enable_testing()
set(CPPUTEST_CREATE_TESTS OFF)
add_subdirectory(libs/cpputest)

# --- 4. Cria o executável de TESTE ---
add_executable(run_tests
    tests/main_test_runner.cpp
    tests/academico/domain/pessoas/pessoa_test.cpp 
    tests/academico/domain/pessoas/aluno_test.cpp 
    tests/utils/string_utils_test.cpp 
    tests/utils/lista_test.cpp 
)

# Informa ao executável de teste onde encontrar os cabeçalhos
target_include_directories(run_tests PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/includes
    ${CMAKE_CURRENT_SOURCE_DIR}/tests
    libs/cpputest/include               
)

# Linka o executável de teste com as bibliotecas
target_link_libraries(run_tests PRIVATE 
    academico_lib
    CppUTest
    CppUTestExt
)

# Adiciona o teste ao CTest
add_test(NAME UnitTests COMMAND run_tests)