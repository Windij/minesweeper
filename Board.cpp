#include "Board.h"
#include <cstdlib>
#include <ctime>

void Board::init(int n, int m, int k) {
    this->n = n;
    this->m = m;
    this->k = k;

    for (int i = 0; i < n; i = i + 1) {
        for (int j = 0; j < m; j++) {
            a[i][j] = '#';
            b[i][j] = '.';
        }
    }

    postavitMiny();
}

void Board::postavitMiny() {
    srand(time(0));

    int cnt = 0;
    while (cnt < k) {
        int x = rand() % n;
        int y = rand() % m;

        if (b[x][y] != '*') {
            b[x][y] = '*';
            cnt++;
        }
    }
}

void Board::show() {
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Board::showAll() {
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}