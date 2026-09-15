#include <iostream>
#include "Board.h"

int main() {
    Board bo;
    bo.init(9, 9, 10);

    cout << "Pole igroka:" << endl;
    bo.show();

    cout << "Realnoe pole:" << endl;
    bo.showAll();

    bo.otkryt(0, 0);
    bo.otkryt(5, 5);
    bo.otkryt(8, 8);

    cout << "Posle otkrytiya:" << endl;
    bo.show();

    return 0;
}