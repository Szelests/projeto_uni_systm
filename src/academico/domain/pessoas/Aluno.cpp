#include "academico/domain/pessoas/Aluno.hpp"
#include "academico/domain/Nota.hpp"
#include "utils/string_utils.hpp"
#include <iostream>
#include <cstdio>
#include <utility> // Para std::move

// Construtor CORRIGIDO para aceitar e mover o unique_ptr
Aluno::Aluno(uint32_t id, const char* nome, const char* cpf, const char* matricula, uint16_t curso_id, std::unique_ptr<IHistoricoAcademico> historico)
    : Pessoa(id, nome, cpf), 
      m_curso_id(curso_id),
      m_historico(std::move(historico)) // Aluno "rouba" a posse do histórico
{
    const char* matricula_valida = matricula ? matricula : "";
    snprintf(m_matricula, TAMANHO_MAX_MATRICULA, "%s", matricula_valida);
    StringUtils::trim(m_matricula);
}

// O resto da implementação continua o mesmo...
const char* Aluno::get_matricula() const {
    return m_matricula;
}
uint16_t Aluno::get_curso_id() const {
    return m_curso_id;
}
void Aluno::set_curso_id(uint16_t id) {
    m_curso_id = id;
}

void Aluno::adicionar_nota(uint16_t disciplina_id, double valor) {
    // Agora usamos o ponteiro -> para chamar o método
    if (m_historico) {
        m_historico->adicionar_nota(Nota(disciplina_id, valor));
    }
}

void Aluno::exibir_detalhes() const {
    std::cout << "--- Detalhes do Aluno ---" << std::endl;
    std::cout << "ID: " << m_id << std::endl;
    std::cout << "Nome: " << m_nome << std::endl;
    std::cout << "CPF: " << m_cpf << std::endl;
    std::cout << "Matricula: " << m_matricula << std::endl;
    std::cout << "Curso (ID): " << m_curso_id << std::endl;
    if (m_historico) {
        std::cout << "Coeficiente de Rendimento (CR): " << m_historico->calcular_cr() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
}