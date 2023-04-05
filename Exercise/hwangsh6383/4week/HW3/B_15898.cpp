#include <bits/stdc++.h>

using namespace std;

int n;
int ingredient[10][4][4];
char color[10][4][4];
pair<int,char> board[5][5];
bool vis[10];
int answer;

void func(int count) {
    if(count == 3)
    {
        int temp = 0;
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(board[i][j].second == 'R')
                    temp += board[i][j].first * 7;
                else if(board[i][j].second == 'B')
                    temp += board[i][j].first * 5;
                else if(board[i][j].second == 'G')
                    temp += board[i][j].first * 3;
                else if(board[i][j].second == 'Y')
                    temp += board[i][j].first * 2;
            }
        }
        answer = max(answer, temp);
        return;
    }
    pair<int,char> storage[5][5];
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            storage[i][j] = board[i][j];
    for(int i = 0; i < n; i++)
    {
        if(vis[i]) continue;
        vis[i] = true;
        int ing[4][4];
        for (int m = 0; m < 4; m++)
            for (int n = 0; n < 4; n++)
                ing[m][n] = ingredient[i][3 - n][m];
        char col[4][4];
        for (int m = 0; m < 4; m++)
            for (int n = 0; n < 4; n++)
                col[m][n] = color[i][3 - n][m];
        for(int k = 0; k <= 1; k++)
        {
            for(int j = 0; j <= 1; j++)
            {
                for(int l = 0; l < 4; l++)
                {
                    int temping[4][4];
                    for (int m = 0; m < 4; m++)
                        for (int n = 0; n < 4; n++)
                            temping[m][n] = ing[3 - n][m];
                    char tempcol[4][4];
                    for (int m = 0; m < 4; m++)
                        for (int n = 0; n < 4; n++)
                            tempcol[m][n] = col[3 - n][m];
                    for (int m = 0; m < 4; m++) {
                        for (int n = 0; n < 4; n++) {
                            board[m + k][n + j].first += temping[m][n];
                            if (board[m + k][n + j].first < 0)
                                board[m + k][n + j].first = 0;
                            else if (board[m + k][n + j].first > 9)
                                board[m + k][n + j].first = 9;
                            if (tempcol[m][n] != 'W')
                                board[m + k][n + j].second = tempcol[m][n];
                        }
                    }
                    func(count + 1);
                    for (int m = 0; m < 5; m++)
                        for (int n = 0; n < 5; n++)
                            board[m][n] = storage[m][n];
                    for (int m = 0; m < 4; m++)
                        for (int n = 0; n < 4; n++)
                            ing[m][n] = temping[m][n];
                    for (int m = 0; m < 4; m++)
                        for (int n = 0; n < 4; n++)
                            col[m][n] = tempcol[m][n];
                }
            }
        }
        vis[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int k = 0; k < 4; k++)
        {
            for(int j = 0; j < 4; j++)
            {
                cin >> ingredient[i][k][j];
            }
        }
        for(int k = 0; k < 4; k++)
        {
            for(int j = 0; j < 4; j++)
            {
                cin >> color[i][k][j];
            }
        }
    }
    func(0);
    cout << answer;
    return 0;
}
