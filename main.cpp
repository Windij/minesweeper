#include <iostream>
#include "Board.h"

int main() {
    Board bo;
    bo.init(9, 9, 10);

    cout << "Realnoe pole:" << endl;
    bo.showAll();

    bo.otkryt(0, 0);

    cout << "Posle otkrytiya (0,0):" << endl;
    bo.show();

    return 0;
}