#include <iostream>
#include "Board.h"

int main() {
    Board bo;
    bo.init(9, 9, 10);

    cout << "Pole igroka:" << endl;
    bo.show();

    cout << "Realnoe pole:" << endl;
    bo.showAll();

    return 0;
}