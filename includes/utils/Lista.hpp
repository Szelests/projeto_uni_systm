#ifndef __LISTA_HPP__
#define __LISTA_HPP__

#include <cstddef>   // Para size_t
#include <stdexcept> // Para std::out_of_range
#include <ostream>   // Para std::ostream
#include <algorithm> // Para std::swap

template <typename T>
class Lista 
{
private:
    // Adicionado prefixo m_ para membros, como no resto do projeto
    T* m_elementos;
    size_t m_capacidade;
    size_t m_tamanho;

    void redimensionar()
    { 
        // Sua lógica de redimensionamento está ótima
        m_capacidade = (m_capacidade == 0) ? 10 : m_capacidade * 2;
        T* novos_elementos = new T[m_capacidade];
        for(size_t i = 0; i < m_tamanho; ++i)
        {
            // std::move pode ser mais eficiente para objetos complexos
            novos_elementos[i] = std::move(m_elementos[i]);
        }
        delete[] m_elementos;
        m_elementos = novos_elementos;
    }

public:
    // --- CONSTRUTOR e DESTRUTOR ---

    // OTIMIZAÇÃO: Construtor não aloca memória inicialmente.
    // Economiza memória para listas que são criadas mas nunca usadas.
    Lista(): m_elementos(nullptr), m_capacidade(0), m_tamanho(0) {}

    ~Lista()
    {
        delete[] m_elementos;
    }

    // --- A "REGRA DOS TRÊS" ---

    // Construtor de Cópia: Cria uma cópia profunda do original.
    Lista(const Lista& original)
        : m_elementos(new T[original.m_capacidade]),
          m_capacidade(original.m_capacidade), 
          m_tamanho(original.m_tamanho)
    {
        for(size_t i = 0; i < m_tamanho; ++i)
        { 
            m_elementos[i] = original.m_elementos[i];
        }
    }

    // Operador de Atribuição de Cópia (idioma copy-and-swap)
    Lista& operator=(Lista outra)
    {
        // Troca os recursos internos com a cópia temporária 'outra'
        std::swap(this->m_elementos, outra.m_elementos);
        std::swap(this->m_tamanho, outra.m_tamanho);
        std::swap(this->m_capacidade, outra.m_capacidade);
        return *this;
    }

    // --- MÉTODOS MODIFICADORES ---
    
    void adicionar(const T& elemento)
    {
        if(m_tamanho == m_capacidade)
        {
            redimensionar();
        }
        m_elementos[m_tamanho++] = elemento;
    }

    void remover_ultimo()
    {
        if(m_tamanho > 0) 
        {
            m_tamanho--;
        }
    }

    void remover(size_t indice)
    {
        if (indice >= m_tamanho)
        {
            throw std::out_of_range("Indice de remocao fora do limite!");
        }
        
        for(size_t i = indice; i < m_tamanho - 1; ++i) 
        {
            m_elementos[i] = m_elementos[i + 1];
        }
        m_tamanho--;
    }

    void limpar()
    {
        m_tamanho = 0;
    }

    // --- MÉTODOS DE ACESSO ---

    T& operator[](size_t indice)
    {
        if(indice >= m_tamanho) 
        {
            throw std::out_of_range("Indice fora do limite!");
        }
        return m_elementos[indice]; 
    }

    const T& operator[](size_t indice) const
    {
        if(indice >= m_tamanho) 
        {
            throw std::out_of_range("Indice fora do limite!");
        }
        return m_elementos[indice];
    }
    
    size_t get_tamanho() const
    {
        return m_tamanho;
    }

    // RENOMEADO: getCapacidade -> get_capacidade
    size_t get_capacidade() const
    {
        return m_capacidade;
    }

    // RENOMEADO: estaVazia -> esta_vazia
    bool esta_vazia() const
    {
        return m_tamanho == 0;
    }
};

// Sobrecarga do operador << para impressão
template <typename T>
std::ostream& operator<<(std::ostream& os, const Lista<T>& lista)
{
    os << "[";
    for (size_t i = 0; i < lista.get_tamanho(); ++i) // RENOMEADO: getTamanho -> get_tamanho
    {
        os << lista[i] << (i == lista.get_tamanho() - 1 ? "" : ", ");
    }
    os << "]";
    return os;
}

#endif // __LISTA_HPP__