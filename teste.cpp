#include <iostream>
#include "Carta.hpp"
using namespace std;

int main(){
    Carta carta('Q', 'C');
    
    cout<<"naipe: "<<carta.peekNaipe()<<endl;
    cout<<"valor: "<<carta.peekValue()<<endl;
    cout<<"cor: " <<carta.peekCor()<<endl;

    cout<<"Flip state: "<<carta.getFaceState()<<endl;
    carta.flipCard();
    cout<<"naipe: "<<carta.peekNaipe()<<endl;
    cout<<"valor: "<<carta.peekValue()<<endl;
    cout<<"cor: " <<carta.peekCor()<<endl;

    cout<<"Flip state: "<<carta.getFaceState()<<endl;
    carta.setFaceState(false);
    cout<<"naipe: "<<carta.peekNaipe()<<endl;
    cout<<"valor: "<<carta.peekValue()<<endl;
    cout<<"cor: " <<carta.peekCor()<<endl;

    cout<<"Flip state: "<<carta.getFaceState()<<endl;

    carta.setFaceState(true);
    char carac = (char)3;
    carta.setValue('3');
    cout<<"naipe: "<<carta.peekNaipe()<<endl;
    cout<<"valor: "<<carta.peekValue()<<endl;
    cout<<"cor: " <<carta.peekCor()<<endl;
    carta.printaCarta();
    //cout<<"Flip state: "<<carta.getFaceState()<<endl;

    return 0;
}
