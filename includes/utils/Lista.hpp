#ifndef __LISTA_HPP__
#define __LISTA_HPP__

#include <cstddef> // Para size_t
#include <iostream>
#include <stdexcept>
#include <algorithm> // Para std::swap

template <typename T>
class Lista 
{
private:
    T* elementos;
    size_t capacidade;
    size_t tamanho;

    void redimensionar()
    { 
        capacidade = (capacidade == 0) ? 1 : capacidade * 2;
        T* novos_elementos = new T[capacidade];
        for(size_t i = 0; i < tamanho; ++i) // BUG CORRIGIDO: i inicializado
        {
            novos_elementos[i] = elementos[i]; // Poderia usar std::move para eficiência
        }
        delete[] elementos;
        elementos = novos_elementos;
    }

public:
    // --- CONSTRUTOR e DESTRUTOR ---
    Lista(): capacidade(10), tamanho(0)
    {
        elementos = new T[capacidade];
    }

    ~Lista()
    {
        delete[] elementos;
    }

    // --- A "REGRA DOS CINCO" (C++11+) ---
    // Inclui construtores e operadores de MOVER (move semantics)
    // Mas vamos focar na Regra dos Três por enquanto.

    // Construtor de Cópia
    Lista(const Lista& original): capacidade(original.capacidade), tamanho(original.tamanho)
    {
        elementos = new T[capacidade];
        for(size_t i = 0; i < tamanho; ++i) // BUG CORRIGIDO: i inicializado
        { 
            elementos[i] = original.elementos[i];
        }
    }

    // Operador de Atribuição de Cópia (usando o idioma copy-and-swap para segurança)
    Lista& operator=(Lista outra) // Recebe por valor para criar uma cópia
    {
        // Troca o conteúdo do objeto atual com o da cópia temporária 'outra'
        std::swap(this->elementos, outra.elementos);
        std::swap(this->tamanho, outra.tamanho);
        std::swap(this->capacidade, outra.capacidade);
        return *this;
        // A cópia temporária 'outra' é destruída ao sair do escopo, liberando a memória antiga.
    }

    // --- MÉTODOS MODIFICADORES ---
    
    void adicionar(const T& elemento)
    {
        if(tamanho == capacidade)
        {
            redimensionar();
        }
        elementos[tamanho] = elemento;
        tamanho++;
    }

    void remover_ultimo()
    {
        if(tamanho > 0) 
        {
            tamanho--;
        }
    }

    void remover(size_t indice)
    {
        if (indice >= tamanho)
        {
            throw std::out_of_range("Indice de remoção fora do range!");
        }
        
        for(size_t i = indice; i < tamanho - 1; ++i) 
        {
            elementos[i] = elementos[i + 1];
        }
        tamanho--;
    }

    void limpar()
    {
        tamanho = 0;
    }

    // --- MÉTODOS DE ACESSO ---

    T& operator[](size_t indice)
    {
        if(indice >= tamanho) 
        {
            throw std::out_of_range("Indice fora do range!");
        }
        return elementos[indice]; 
    }

    // Versão const para acesso a partir de objetos constantes
    const T& operator[](size_t indice) const
    {
        if(indice >= tamanho) 
        {
            throw std::out_of_range("Indice fora do range!");
        }
        return elementos[indice];
    }
    
    size_t getTamanho() const
    {
        return tamanho;
    }

    size_t getCapacidade() const
    {
        return capacidade;
    }

    bool estaVazia() const
    {
        return tamanho == 0;
    }
};

// Sobrecarga do operador << para impressão (melhor prática)
template <typename T>
std::ostream& operator<<(std::ostream& os, const Lista<T>& lista)
{
    os << "[";
    for (size_t i = 0; i < lista.getTamanho(); ++i)
    {
        os << lista[i] << (i == lista.getTamanho() - 1 ? "" : ", ");
    }
    os << "]";
    return os;
}


#endif // __LISTA_HPP__