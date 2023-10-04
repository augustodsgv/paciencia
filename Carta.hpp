#include <iostream>
#ifndef CARTA_HPP
#define CARTA_HPP

class Carta{
    public:
        Carta(char valor, char naipe, bool isFaceUp = false);
        Carta(int valor, int naipe, bool isFaceUp = false);

        // Funções específicas de cartas
        char peekValue();                               // Visualiza a carta, caso ela esteja de face para cima. Caso contrário, retorna 'X'
        char peekNaipe();
        char peekCor();
        void flipCard();                                // Vira a carta

        // Getters
        char getValue();
        char getNaipe();
        char getCor();
        bool getFaceState();
        Carta * getCopy();

        // Setters
        void setValue(char valor);
        void setValue(int valor);
        void setNaipe(char naipe);
        void setNaipe(int valor);
        void setFaceState(bool newFaceState);           // Coloca a carta num estado específico
        
        void printaCarta();
        
    private:
        // Funções de checagem
        bool isValidValue(char valor);
        bool isValidNaipe(char naipe);

        // Atributos
        char valor;
        char naipe;
        char cor;
        bool isFaceUp;          // Indica se esta com a face para cima
        
};
#endif /*CARTA_HPP*/