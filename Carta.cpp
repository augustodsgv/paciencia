#include "Carta.hpp"
#include <iostream>
#include <stdexcept>

const char validValues[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'D', 'J', 'Q', 'K'};
const char validNaipes[] = {'O', 'E', 'C', 'P'};    // Ouros, Espadas, Copas, Paus

Carta::Carta(char valor, char naipe, bool isFaceUp){       // A carta
    if (!isValidValue(valor)) throw std::invalid_argument("Criando carta com VALOR inválido");
    if(!isValidNaipe(naipe)) throw std::invalid_argument("Criando carta com NAIPE inválido");
    this->valor = valor;
    this->naipe = naipe;
    this->isFaceUp = isFaceUp;

    // Tratando as cores
    if (naipe == 'O' || naipe == 'C')   // Caso seja Ouros ou copas
        this->cor = 'V';
    else                                // Caso seja Espadas ou Paus
        this->cor = 'P';
}

Carta::Carta(int valor, int naipe, bool isFaceUp){       // A carta
    if(valor < 1 || valor > 13){
        std::cout<<"valor: "<<valor<<std::endl;
        throw std::invalid_argument("Criando carta com VALOR inválido");
    }
    if(naipe < 0 || naipe > 3){
        std::cout<<naipe<<std::endl;
        throw std::invalid_argument("Criando carta com NAIPE inválido");
    }
    this->valor = validValues[valor - 1];
    this->naipe = validNaipes[naipe];
    this->isFaceUp = isFaceUp;

    // Tratando as cores
    if (naipe == 'O' || naipe == 'C')   // Caso seja Ouros ou copas
        this->cor = 'V';
    else                                // Caso seja Espadas ou Paus
        this->cor = 'P';
}

// Funções específicas de cartas
// Visualiza a carta, caso ela esteja de face para cima. Caso contrário, retorna 'X'
char Carta::peekValue(){
    if (!this->getFaceState()) return 'X';       // Caso esteja de face para baixo
    return this->getValue();                    // Caso esteja de face para cima
}

char Carta::peekNaipe(){
    if (!this->getFaceState()) return 'X';       // Caso esteja de face para baixo
    return this->getNaipe();                    // Caso esteja de face para cima
}

char Carta::peekCor(){
    if (!this->getFaceState()) return 'X';       // Caso esteja de face para baixo
    return this->getCor();                    // Caso esteja de face para cima
}

// Vira a carta
void Carta::flipCard(){
    this->isFaceUp = !this->isFaceUp;
}                             

// Getters
char Carta::getValue(){
    return this->valor;
}

char Carta::getNaipe(){
    return this->naipe;
}

char Carta::getCor(){
    return this->cor;
}

bool Carta::getFaceState(){
    return this->isFaceUp;
}

Carta * Carta::getCopy(){
    Carta * cartaCopia = new Carta(this->valor, this->naipe);
    return cartaCopia;
}


// Setters
void Carta::setValue(char valor){
    if(!isValidValue(valor)) throw std::invalid_argument("Alterando carta para VALOR inválido");
    this->valor = valor;
}

// Setando os valor com base nos valores numéricos das cartas 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K';
void Carta::setValue(int valor){
    if(valor < 1 || valor > 13){
        std::cout<<"valor: "<<valor<<std::endl;
        throw std::invalid_argument("Alterando carta para VALOR inválido");
    }
    this->valor = validValues[valor - 1];
}

void Carta::setNaipe(char naipe){
    if(!isValidNaipe(naipe)) throw std::invalid_argument("Alterando carta para NAIPE inválido");
    this->naipe = naipe;
    // Tratando as cores
    if (naipe == 'O' || naipe == 'C')   // Caso seja Ouros ou copas
        this->cor = 'V';
    else                                // Caso seja Espadas ou Paus
        this->cor = 'P';
}

// Setando o naipe da carta com base no vetor ['O', 'E', 'C', 'P']
void Carta::setNaipe(int naipe){
    if(naipe < 0 || naipe > 3) throw std::invalid_argument("Alterando carta para NAIPE inválido: ");
    this->naipe = validNaipes[naipe];
    // Tratando as cores
    if (this->naipe == 'O' || this->naipe == 'C')   // Caso seja Ouros ou copas
        this->cor = 'V';
    else                                // Caso seja Espadas ou Paus
        this->cor = 'P';
}

// Coloca a carta num estado específico
void Carta::setFaceState(bool newFaceState){           
    this->isFaceUp = newFaceState;
}

// Funções de checagem
bool Carta::isValidValue(char valor){
    for (int i = 0; i < 14; i++)
        if (valor == validValues[i]) return true;
    // Caso não esteja na lista de válidos
    return false; 
}

bool Carta::isValidNaipe(char naipe){
    for (int i = 0; i < 4; i++)
        if(naipe == validNaipes[i]) return true;
    // Caso não seja um naipe válido
    return false;
}

void Carta::printaCarta(){
    std::cout<<this->valor;
    switch(this->naipe){
        case 'O':
            std::cout<<" <>";
            break;
        case 'C':
            std::cout<<" <3";
            break;
        case 'E':
            std::cout<<" -»";
            break;
        case 'P':
            std::cout<<" ŧŧ";
            break;
    }
}

