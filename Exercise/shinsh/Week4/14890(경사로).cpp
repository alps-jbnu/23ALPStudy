#include<bits/stdc++.h>
using namespace std;

int n, L;
int board[105][105];
int resRow, resCol;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> L;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    //행 검사
    for (int i = 0; i < n; i++) {
        int cntRow = 1;         //현재까지의 연속된 같은 높이의 계단 수
        bool flagRow = true;    //길을 만들 수 있는지

        for (int j = 0; j + 1 < n; j++) {
            if (board[i][j] == board[i][j + 1])
                cntRow++;

            else if (board[i][j] - board[i][j + 1] == -1) {     //높이가 높아질 경우
                if (cntRow >= L)
                    cntRow = 1;
                else
                    flagRow = false;
            }

            else if (board[i][j] - board[i][j + 1] == 1) {      //높이가 낮아질 경우
                if (cntRow < 0)
                    flagRow = false;
                else
                    cntRow = -(L - 1);
            }

            else
                flagRow = false;        //위 사례를 제외하면 모두 불가
        }

        if (cntRow >= 0 && flagRow)
            resRow++;
    }

    //열 검사
    for (int i = 0; i < n; i++) {
        int cntCol = 1;         //현재까지의 연속된 같은 높이의 계단 수
        bool flagCol = true;    //길을 만들 수 있는지

        for (int j = 0; j + 1 < n; j++) {
            if (board[j][i] == board[j + 1][i])
                cntCol++;

            else if (board[j][i] - board[j + 1][i] == -1) {     //높이가 높아질 경우
                if (cntCol >= L)
                    cntCol = 1;
                else
                    flagCol = false;
            }

            else if (board[j][i] - board[j + 1][i] == 1) {      //높이가 낮아질 경우
                if (cntCol < 0)
                    flagCol = false;
                else
                    cntCol = -(L - 1);
            }

            else
                flagCol = false;        //위 사례를 제외하면 모두 불가
        }

        if (cntCol >= 0 && flagCol)
            resCol++;
    }

    cout << resRow + resCol;

    return 0;
}