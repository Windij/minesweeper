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

int Board::countNear(int x, int y) {
    int c = 0;

    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (b[i][j] == '*') {
                c++;
            }
        }
    }

    return c;
}

void Board::otkryt(int x, int y) {
    if (b[x][y] == '*') {
        a[x][y] = '*';
        return;
    }

    int c = countNear(x, y);

    if (c == 0) {
        a[x][y] = '.';
    } else {
        a[x][y] = c + '0';
    }
}