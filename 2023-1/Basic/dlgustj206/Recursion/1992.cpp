#include <iostream>
#include <string>
using namespace std;

string video[64];

void printCompResult(int, int, int);

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> video[i];

    printCompResult(n, 0, 0);
}

void printCompResult(int size, int y, int x){
    char curr = video[y][x];

    for (int i = y; i < y + size; i++)
        for (int j = x; j < x + size; j++)
            if (video[i][j] != curr)
            {
                cout << '(';
                printCompResult(size / 2, y, x);
                printCompResult(size / 2, y, x + size / 2);
                printCompResult(size / 2, y + size / 2, x);
                printCompResult(size / 2, y + size / 2, x + size / 2);
                cout << ')';
                return;
            }
    cout << curr;
}