#include <iostream>
#include "Carta.hpp"


class Monte{
    public:
        Monte(int maxSize = 52);        // Cria o monte, com tamanho padrão 52
        Carta * getCarta(int posicao);
        // Funções específicas de montes de carta
        Carta * peek();           // espia a carta de cima do monte
        Carta * pop();            // Remove a carta de cima do monte
        Carta * remove(int posicao);      // Remove a carta da posição especificada
        //Carta * removeMany(int posicaoInicio, int posicaoFim);      // remove todas as cartas de um intervalo
        void push(Carta * novaCarta);   // Isere uma nova carta no topo
        void insert(Carta * novaCarta, int posicao);    // Insere uma carta na posiação indicada
        void embaralha();                   // Muda a posição de todas as cartas aleatóriamente
        void flipAll();                     // Gira o baralho, mudando a posição das cartas para uma posição inversa e colocando as cartas no sentido face para baixo
        Monte * cortaMonte(int posicao);    // Corta o monte atual e remove as cartas do ponto de corte pra frente em outro monte
        void printaMonte();


        // Getters
        bool isEmpty();
        bool isFull();
        int getNCartas();
        int getMaxSize();
        Monte * getMonte();     // Retorna uma cópia do monte
    private:
        int nCartas;
        int maxSize;
        Carta ** monte;      // Vetor que representa o monte, um vetor para ponteiros de cartas (alocadas dinamicamente)
};