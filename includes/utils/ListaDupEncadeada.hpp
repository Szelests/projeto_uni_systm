#ifndef __LISTA_DUPLAMENTE_ENCADEADA_HPP__
#define __LISTA_DUPLAMENTE_ENCADEADA_HPP__

#include <iostream>
#include <stdexcept> 
#include <cstdint>

template <typename T>

class ListaDuplamenteEncadeada
{
    private:

        /**
         * @brief É a estrutura interna que representa um nó da lista.
         */
        typedef struct No 
        {
            T dados;
            No* prox;
            No* prev;
            No(const T& valor): dados(valor), prox(nullptr), prev(nullptr) {}
        } No;

        No* cabeca; // Ponteiro para o primeiro elemento
        No* cauda; // Ponteiro para o último elemento
        uint16_t tamanho;

    public:
        // --- CONSTRUTORA - E - DESTRUTORA ---
        /**
         * @brief Construtora
         * @details Está vazia e a iniciação é feita na Lista acima
         */
        ListaDuplamenteEncadeada():cabeca(nullptr), cauda(nullptr), tamanho(0){}

        /**
         * @brief Destrutora
         * @details Destrói os elementos da lista e assigna nullptr aos ponteiros envolvidos
         */
        ~ListaDuplamenteEncadeada()
        {
            No* atual = cabeca;
            while(atual != nullptr) 
            {
                No* proximo = atual->prox;
                delete atual;
                atual = proximo;
            }
            cauda = nullptr;
            cabeca = nullptr;
        }

        // --- MÉTODOS AUXILIARES ---
        /**
         * @brief Retorna o tamanho da Lista
         * @return uint16_t tamanho
         */
        uint16_t get_tamanho() const
        {
            return tamanho;
        }

        /**
         * @brief Confere se está vazia
         * @return bool check
         */
        bool vazia() const
        {
            return tamanho == 0;
        }

        // --- MÉTODOS DE MANIPULAÇÂO ---
        /**
         * @brief Adiciona elementos à Lista
         * @param const T& elemento
         */
        void adicionar(const T& elemento) 
        {
            No* novo_elemento = new No(elemento);

            if(vazia()) 
            {
                cabeca = novo_elemento;
                cauda = novo_elemento;
            } else 
            {
                cauda->prox = novo_elemento;
                novo_elemento->prev = cauda;
                cauda = novo_elemento;
            }

            tamanho++;
        }

        // --- Remover Sobrecarregados ---
        /**
         * @brief Remove um elemento da lista e retorna um check
         * @param const T& elemento
         * @return bool - true se um elemento foi removido, false se a lista estava vazia.
         */
        bool remover(const T& elemento)
        {
            No* atual = cabeca;

            while(atual != nullptr && !(atual->dados == elemento)) // Requer que T tenha operador== 
            {
                atual = atual->prox;
            }

            if(atual == nullptr) 
            {
                return false;
            }

            if(atual->prev != nullptr) 
            {
                atual->prev->prox = atual->prox;
            } else 
            {
                cabeca = atual->prox;
            }

            if(atual->prox != nullptr) 
            {
                atual->prox->prev = atual->prev;
            } else 
            {
                cauda = atual->prev;
            }

            delete atual;
            tamanho--;

            return true;
        } 

        /**
         * @brief Remove o último elemento da Lista
         * @return bool - true se um elemento foi removido, false se a lista estava vazia.
         */
        bool remover()
        {
            if(vazia()) 
            {
                return false;
            }

            // Se só há um elemento
            if(cabeca == cauda)
            {
                delete cabeca;
                cabeca = nullptr;
                cauda = nullptr;
            } else // Se há mais de um elemento
            {
                No* noParaRemover = cauda;
                cauda = cauda->prev;
                cauda->prox = nullptr;
                delete noParaRemover;
            }

            tamanho--;
            return true;
        }

        /**
         * @brief Remove um elemento de acordo com o índice
         * @param uint16_t
         * @return bool - true se um elemento foi removido, false se a lista estava vazia.
         */
        bool remover(uint16_t indice)
        {
            if(vazia()) 
            {
                return false;
            }

            /**
             * @note Caso especial: Indice fora do limite - remove o último
             */
            if(indice >= tamanho)
            {
                std::cout << "Aviso: Indice " << indice << "fora do limite (tamanho=" << tamanho << "). Removendo o úlitmo!" << std::endl;
                return remover();
            }


            No* noParaRemover = cabeca;

            /**
             * @note Caso especial:
             */
            if(indice == 0) 
            {
                cabeca = noParaRemover->prox;
                if(cabeca != nullptr) 
                {
                    cabeca->prev = nullptr;
                } else 
                {
                    cauda = nullptr;
                }
            } else
            {
                // Percorre a Lista até o no de índice desejado
                uint16_t i = 0;
                for(i; i < indice; i++)
                {
                    noParaRemover = noParaRemover->prox;
                }

                // Religa os ponteiros dos vizinhos
                noParaRemover->prev->prox = noParaRemover->prox;

                // Se não for o último, o próximo dele precisa apontear para trás
                if(noParaRemover->prox != nullptr)
                {
                    noParaRemover->prox->prev = noParaRemover->prev;
                } else 
                {
                    //Se for o último atualiza a cauda
                    cauda = noParaRemover->prev;
                }
            }

            delete noParaRemover;
            tamanho--;
            return true;

        }


        // --- MÉTODO DE VISUALIZAÇÂO ---
        /**
         * @brief Imprime o elemento
         */
        void imprimir() const 
        {
            No* atual = cabeca;
            std::cout << "Lista: [ ";
            while(atual != nullptr)
            {
                std::cout << atual->dados << " ";
                atual = atual->prox;
            }
            std::cout << "]" << std::endl; 
        }
};

#endif // __LISTA_DUPLAMENTE_ENCADEADA_HPP__