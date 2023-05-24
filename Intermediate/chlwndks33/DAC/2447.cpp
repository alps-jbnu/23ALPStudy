//baekjoon - 2447번 별찍기 - 10

#include <iostream>
using namespace std;

int n;
char board[6562][6562];

void func(int a, int b, int n) {
    if(n==1) {
        board[a][b] = '*';
        return;
    }

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(i==1 && j==1) {
                continue;
            }
            func(a+i*n/3,b+j*n/3,n/3);
        }
    }
    return;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(&board[0][0], &board[0][0] + 6562 * 6562, ' ');
    cin >> n;
    func(0,0,n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}