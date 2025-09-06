#ifndef __GERENCIADOR_DE_PESSOAS_HPP__
#define __GERENCIADOR_DE_PESSOAS_HPP__

#include <memory> // Para std::unique_ptr
#include "../utils/Lista.hpp"
#include "../domain/pessoas/Pessoa.hpp"
#include "../domain/pessoas/Aluno.hpp"
#include "../domain/pessoas/Professor.hpp"

class GerenciadorDePessoas 
{
private:
    // A lista armazena ponteiros únicos, garantindo que a memória seja
    // liberada automaticamente quando a lista for destruída.
    Lista<std::unique_ptr<Pessoa>> m_pessoas;
    uint16_t m_proximo_id_pessoa;

public:
    // Construtor padrão
    GerenciadorDePessoas();

    // Métodos para criar e adicionar novas pessoas à lista
    Aluno& criar_aluno(
        const char* nome, 
        const char* cpf, 
        const char* matricula, 
        uint16_t cursoId
    );

    Professor& criar_professor(
        const char* nome, 
        const char* cpf, 
        const char* idFuncional, 
        double salario, 
        uint16_t departamentoId
    );

    // Métodos para buscar pessoas na lista
    Pessoa* get_pessoa_por_id(long id) const;
    Aluno* get_aluno_por_id(long id) const;
    Professor* get_professor_por_id(long id) const; // Adicionei este para consistência

    // Método para listar subconjuntos de pessoas
    Lista<Aluno*> listar_todos_alunos() const;
    
    // Boa prática: desabilitar cópia de gerenciadores para evitar confusão de propriedade
    GerenciadorDePessoas(const GerenciadorDePessoas&) = delete;
    GerenciadorDePessoas& operator=(const GerenciadorDePessoas&) = delete;
};

#endif // __GERENCIADOR_DE_PESSOAS_HPP__