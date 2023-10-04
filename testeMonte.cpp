#include <iostream>
#include "Monte.hpp"
#include "Carta.hpp"

int main(){
    // Criando cartas para se colocar no monte
    Carta ** pilha = new Carta*[60];
    Monte * monte = new Monte();
    //A, 1, 2, 3, 4, 5, 6, 7, 8, 9, J, Q, K
    int cont = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 13; j++)
            pilha[cont++] = new Carta(j + 1, i, true);

    for (int i = 0; i < 52; i++){
        monte->push(pilha[i]);
    }
    // monte->flipAll();
    Monte * monte2 = monte->getMonte();

    monte->printaMonte();


    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;

    for (int i = 0; i < 26; i++){
        monte->pop();
        monte->peek()->printaCarta();

    }

    monte->printaMonte();

    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    // monte2->printaMonte();

    std::cout<<std::endl;
    monte2->flipAll();

    // monte2->printaMonte();


    return 0;
}