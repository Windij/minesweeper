#pragma once
#include <iostream>
using namespace std;

class Board {
public:
    void init(int n, int m, int k);
    void show();
    void showAll();
    void otkryt(int x, int y);
    int countNear(int x, int y);

private:
    char a[20][20];
    char b[20][20];
    int n, m, k;
    void postavitMiny();
};