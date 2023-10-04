#include <iostream>
#include "Carta.hpp"
#include "Monte.hpp"

int main() {
    try {
        // Test creating cards
        Carta carta1('A', 'O', true);
        Carta carta2(2, 1, false);
        Carta carta3('Q', 'E', false);

        // Test flipping cards
        carta1.flipCard();
        carta2.flipCard();

        // Test peek functions
        std::cout << "Carta 1: " << carta1.peekValue() << carta1.peekNaipe() << carta1.peekCor() << std::endl;
        std::cout << "Carta 2: " << carta2.peekValue() << carta2.peekNaipe() << carta2.peekCor() << std::endl;
        std::cout << "Carta 3: " << carta3.peekValue() << carta3.peekNaipe() << carta3.peekCor() << std::endl;

        // Test creating monte
        Monte monte(5);
        monte.push(&carta1);
        monte.push(&carta2);
        monte.push(&carta3);

        // Test getCarta
        Carta* carta = monte.getCarta(1);
        carta->printaCarta();
        std::cout << std::endl;

        // Test peek and flip on monte
        Carta* cartaMonte = monte.peek();
        cartaMonte->printaCarta();
        std::cout << std::endl;

        monte.flipAll();
        monte.printaMonte();
        std::cout << std::endl;

        // Test pop and remove
        Carta* cartaRemovida = monte.pop();
        cartaRemovida->printaCarta();
        std::cout << std::endl;

        Carta* cartaRemovida2 = monte.remove(1);
        cartaRemovida2->printaCarta();
        std::cout << std::endl;

        // Test push and insert
        Carta novaCarta('2', 'C', true);
        monte.push(&novaCarta);
        monte.printaMonte();
        std::cout << std::endl;

        Carta novaCarta2('4', 'E', true);
        monte.insert(&novaCarta2, 1);
        monte.printaMonte();
        std::cout << std::endl;

        // Test isEmpty, isFull, getNCartas, and getMaxSize
        std::cout << "Monte is empty: " << monte.isEmpty() << std::endl;
        std::cout << "Monte is full: " << monte.isFull() << std::endl;
        std::cout << "Number of cards: " << monte.getNCartas() << std::endl;
        std::cout << "Maximum size: " << monte.getMaxSize() << std::endl;

        // Test getMonte
        Monte* copiaMonte = monte.getMonte();
        copiaMonte->printaMonte();
        std::cout << std::endl;

        // Clean up dynamically allocated memory
        delete copiaMonte;

    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
