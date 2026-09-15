#include "Game.h"
#include <iostream>
using namespace std;

void Game::start() {
    while (true) {
        cout << endl;
        cout << "=== MINESWEEPER ===" << endl;
        cout << "1 - Лёгкий (9x9, 10 min)" << endl;
        cout << "2 - Средний (16x16, 40 min)" << endl;
        cout << "3 - Сложный (16x30, 99 min)" << endl;
        cout << "0 - Выйти" << endl;
        cout << "Выберите: ";

        int v;
        cin >> v;

        if (v == 1) {
            play(9, 9, 10);
        } else if (v == 2) {
            play(16, 16, 40);
        } else if (v == 3) {
            play(16, 30, 99);
        } else if (v == 0) {
            break;
        } else {
            cout << "Некоректный ввод" << endl;
        }
    }
}

void Game::play(int r, int c, int mines) {
    board.init(r, c, mines);

    while (true) {
        board.show();

        int x, y;
        char act;

        cout << "Координаты (строка столбец): ";
        cin >> x >> y;

        cout << "Действие (o - открыть, f - флаг): ";
        cin >> act;

        if (act == 'o') {
            board.otkryt(x, y);

            if (board.isMine(x, y)) {
                board.show();
                cout << endl << "БУМ! Проигрыш:(" << endl;
                board.showAll();
                return;
            }
        } else if (act == 'f') {
            board.flag(x, y);
        } else {
            cout << "Некоректный ввод" << endl;
            continue;
        }

        if (board.isWin()) {
            board.show();
            cout << endl << "Победа!" << endl;
            return;
        }
    }
}