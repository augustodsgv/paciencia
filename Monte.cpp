#include <iostream>
#include <stdexcept>
#include "Carta.hpp"
#include "Monte.hpp"


// Cria o monte, com tamanho padrão 52
Monte::Monte(int maxSize){
    this->maxSize = maxSize;
    this->nCartas = 0;
    this->monte = new Carta*[maxSize];      // Alocando o vetor de Cartas
}

// Retorna uma cópia da carta da posição indicada
Carta * Monte::getCarta(int posicao){
    if(posicao > this->nCartas) throw std::out_of_range("Pedindo uma carta de posição maior do que o monte");
    return this->monte[posicao]->getCopy();
}

// Funções específicas de montes de carta
// espia a carta de cima do monte
Carta * Monte::peek(){
    return this->monte[nCartas - 1]->getCopy();
}

// Remove a carta de cima do monte
Carta * Monte::pop(){
    if (isEmpty()) throw std::out_of_range("Removendo de um monte vazio");
    nCartas--;
    return this->monte[nCartas];        // Não foi feito o "-1" pois o nCartas já foi decrementado
}
// Remove a carta da posição especificada
Carta * Monte::remove(int posicao){
    if(posicao > this->nCartas) throw std::out_of_range("Retirando carta de posição maior do que o monte");
    Carta * cartaRemovida = this->monte[posicao];
    // Fazendo um "roll" de todas as cartas para uma posição anterior
    for (int i = posicao; i < nCartas - 1; i++){        // -1 por o índice iniciar em 0 e -1 pois a última carta do monte não será "rolada"
        this->monte[i] = this->monte[i + 1];
    }
    this->nCartas--;
    return cartaRemovida;
}
//Carta * removeMany(int posicaoInicio, int posicaoFim);      // remove todas as cartas de um intervalo
// Insere uma nova carta no topo
void Monte::push(Carta * novaCarta){
    this->monte[nCartas++] = novaCarta;
}

// Insere uma carta na posiação indicada
void Monte::insert(Carta * novaCarta, int posicao){
    if (isFull())   throw std::out_of_range("Inserindo em um monte que está cheio");
    if (posicao > this->nCartas)    throw std::out_of_range("inserindo em uma posição maior do que o tamanho do monte");
    // Deve-se fazer um "roll" das cartas da posição até o final para manter a ordem das cartas
    for(int i = this->nCartas; i > posicao; i--)      // Aqui usa-se somente nCartas pois esse esta, agora, batendo com a posição do índice, mas será atualizado posteriormente
        this->monte[i] = this->monte[i - 1];
    this->monte[posicao] = novaCarta;
    this->nCartas++;
}
// Muda a posição de todas as cartas aleatóriamente
// TODO
void Monte::embaralha(){}

// "Gira" o baralho, mudando a posição das cartas para uma posição inversa e colocando as cartas no sentido face para baixo
void Monte::flipAll(){
    Carta ** novoMonte = new Carta*[this->maxSize];
    int nCartasOld = this->nCartas;             // nCartas precisa da variável auxiliar por que o "pop" diminui o nCartas
    for (int i = 0; i < nCartasOld; i++){
        novoMonte[i] = this->pop();
        novoMonte[i]->flipCard();
    }
    this->nCartas = nCartasOld;
    this->monte = novoMonte;
    // TODO: Fazer o garbage collecting do monte antigo

}

// Corta o monte atual e remove as cartas do ponto de corte pra frente em outro monte
// A carta da posição fica no monte original
Monte * Monte::cortaMonte(int posicao){
    if (this->nCartas < posicao || posicao < 0) throw std::out_of_range("Cortando o monte em uma posição inválida");
    Monte * segundaParteMonte = new Monte();
    while (this->nCartas -1 > posicao){
        segundaParteMonte->push(this->remove(posicao));
    }
}

// Getters
bool Monte::isEmpty(){
    return this->nCartas == 0;
}

bool Monte::isFull(){
    return this->nCartas == this->maxSize;
}

int Monte::getNCartas(){
    return this->nCartas;
}

int Monte::getMaxSize(){
    return this->maxSize;
}

// Retorna uma cópia do monte
Monte * Monte::getMonte(){
    Monte * copiaMonte = new Monte(this->maxSize);
    for (int i = 0; i < this->nCartas; i++){
        Carta * novaCarta = this->monte[i]->getCopy();
        copiaMonte->push(novaCarta);
    }
    return copiaMonte;
}

void Monte::printaMonte(){
    for(int i = 0; i < this->nCartas; i++){
        std::cout<<i + 1<<": ";
        this->monte[i]->printaCarta();
        std::cout<<std::endl;
    }
}
