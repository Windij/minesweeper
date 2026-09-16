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
    cout << "  ";
    for (int j = 0; j < m; j++) {
        if (j < 10) {
            cout << " ";
        }
        cout << j << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        if (i < 10) {
            cout << " ";
        }
        cout << i << " ";

        for (int j = 0; j < m; j++) {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void Board::showAll() {
    cout << endl;
    cout << "  ";
    for (int j = 0; j < m; j++) {
        if (j < 10) {
            cout << " ";
        }
        cout << j << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        if (i < 10) {
            cout << " ";
        }
        cout << i << " ";

        for (int j = 0; j < m; j++) {
            cout << b[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

int Board::countNear(int x, int y) {
    int c = 0;

    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i < 0 || i >= n || j < 0 || j >= m) {
                continue;
            }

            if (b[i][j] == '*') {
                c++;
            }
        }
    }

    return c;
}

void Board::otkryt(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return;
    }

    if (a[x][y] != '#') {
        return;
    }

    if (b[x][y] == '*') {
        a[x][y] = '*';
        return;
    }

    int c = countNear(x, y);

    if (c == 0) {
        a[x][y] = '.';

        for (int i = x - 1; i <= x + 1; i++) {
            for (int j = y - 1; j <= y + 1; j++) {
                otkryt(i, j);
            }
        }
    } else {
        a[x][y] = c + '0';
    }
}

bool Board::isWin() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[i][j] != '*' && a[i][j] == '#') {
                return false;
            }
        }
    }
    return true;
}

bool Board::isMine(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return false;
    }
    return b[x][y] == '*';
}

void Board::flag(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return;
    }

    if (a[x][y] == '#') {
        a[x][y] = 'F';
    } else if (a[x][y] == 'F') {
        a[x][y] = '#';
    }
}