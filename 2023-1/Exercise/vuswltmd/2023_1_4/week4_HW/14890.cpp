//14890 경사로
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int N; // 지도의 크기 N x N
int L; // 경사로 길이
int board[105][105];
int board2[105][105];
int ans = 0;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            board2[j][i] = board[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        bool can_road = true;
        int before_road = 1;

        for (int j = 0; j < N - 1; j++) {
            if (board[i][j] == board[i][j + 1]) before_road++;
            else if (board[i][j] == board[i][j + 1] + 1) {

                bool flag = false;
                int Standard = board[i][j+1];

                for (int k = j + 1; k < j + 1 + L; k++)
                {
                    if (board[i][k] != Standard) {
                        flag = true;
                        break;
                    }
                }

                if (flag == true) {
                    can_road = false;
                    break;
                }
                else {
                    j = j + L - 1;
                    before_road = 0;
                }

            }
            else if (board[i][j] + 1 == board[i][j + 1]) {
                if (before_road >= L)
                {
                    before_road = 1;
                }
                else
                {
                    can_road = false;
                    break;
                }
            }
            else if (abs(board[i][j] - board[i][j + 1]) >= 2)
            {
                can_road = false;
                break;
            }
        }
        if (can_road == true)
        {
            ans++;
        }

    }

    for (int i = 0; i < N; i++) {
        bool can_road = true;
        int before_road = 1;

        for (int j = 0; j < N - 1; j++) {
            if (board2[i][j] == board2[i][j + 1]) before_road++;
            else if (board2[i][j] == board2[i][j + 1] + 1) {

                bool flag = false;
                int Standard = board2[i][j+1];
                for (int k = j + 1; k < j + 1 + L; k++)
                {
                    if (board2[i][k] != Standard) {
                        flag = true;
                        break;
                    }
                }

                if (flag == true) {
                    can_road = false;
                    break;
                }
                else {
                    j = j + L - 1;
                    before_road = 0;
                }

            }
            else if (board2[i][j] + 1 == board2[i][j + 1]) {
                if (before_road >= L)
                {
                    before_road = 1;
                }
                else
                {
                    can_road = false;
                    break;
                }
            }
            else if (abs(board2[i][j] - board2[i][j + 1]) >= 2)
            {
                can_road = false;
                break;
            }
        }
        if (can_road == true)
        {
            ans++;
        }

    }

    cout << ans;
}



