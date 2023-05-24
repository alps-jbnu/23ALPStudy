#include <iostream>
#include <algorithm>

using namespace std;

bool tiles[9][9];
int board[9][9];
bool columns[9][9];
bool rows[9][9];
bool square[3][3][9];
int answer[9][9];

void dfs(int index) {
    if(index > 80)
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(!board[i][j])
                    break;
                answer[i][j] = board[i][j];
            }
        }
        return;
    }
    int x = index / 9;
    int y = index % 9;
    if(!board[x][y])
    {
        if(x <= 7 && !board[x + 1][y])
        {
            for(int i = 0; i < 9; i++)
            {
                for(int j = i + 1; j < 9; j++)
                {
                    if(!tiles[i][j])
                    {
                        if(!columns[x][i] && !rows[y][i] && !square[x / 3][y / 3][i]
                        && !columns[x + 1][j] && !rows[y][j] && !square[(x + 1) / 3][y / 3][j])
                        {
                            tiles[i][j] = true;
                            board[x][y] = i + 1;
                            columns[x][i] = true;
                            rows[y][i] = true;
                            square[x / 3][y / 3][i] = true;
                            board[x + 1][y] = j + 1;
                            columns[x + 1][j] = true;
                            rows[y][j] = true;
                            square[(x + 1) / 3][y / 3][j] = true;
                            dfs(index + 1);
                            tiles[i][j] = false;
                            board[x][y] = 0;
                            columns[x][i] = false;
                            rows[y][i] = false;
                            square[x / 3][y / 3][i] = false;
                            board[x + 1][y] = 0;
                            columns[x + 1][j] = false;
                            rows[y][j] = false;
                            square[(x + 1) / 3][y / 3][j] = false;
                        }
                        if(!columns[x][j] && !rows[y][j] && !square[x / 3][y / 3][j]
                           && !columns[x + 1][i] && !rows[y][i] && !square[(x + 1) / 3][y / 3][i])
                        {
                            tiles[i][j] = true;
                            board[x][y] = j + 1;
                            columns[x][j] = true;
                            rows[y][j] = true;
                            square[x / 3][y / 3][j] = true;
                            board[x + 1][y] = i + 1;
                            columns[x + 1][i] = true;
                            rows[y][i] = true;
                            square[(x + 1) / 3][y / 3][i] = true;
                            dfs(index + 1);
                            tiles[i][j] = false;
                            board[x][y] = 0;
                            columns[x][j] = false;
                            rows[y][j] = false;
                            square[x / 3][y / 3][j] = false;
                            board[x + 1][y] = 0;
                            columns[x + 1][i] = false;
                            rows[y][i] = false;
                            square[(x + 1) / 3][y / 3][i] = false;
                        }
                    }
                }
            }
        }
        if(y <= 7 && !board[x][y + 1])
        {
            for(int i = 0; i < 9; i++)
            {
                for(int j = i + 1; j < 9; j++)
                {
                    if(!tiles[i][j])
                    {
                        if(!columns[x][i] && !rows[y][i] && !square[x / 3][y / 3][i]
                           && !columns[x][j] && !rows[y + 1][j] && !square[x / 3][(y + 1) / 3][j])
                        {
                            tiles[i][j] = true;
                            board[x][y] = i + 1;
                            columns[x][i] = true;
                            rows[y][i] = true;
                            square[x / 3][y / 3][i] = true;
                            board[x][y + 1] = j + 1;
                            columns[x][j] = true;
                            rows[y + 1][j] = true;
                            square[x / 3][(y + 1) / 3][j] = true;
                            dfs(index + 2);
                            tiles[i][j] = false;
                            board[x][y] = 0;
                            columns[x][i] = false;
                            rows[y][i] = false;
                            square[x / 3][y / 3][i] = false;
                            board[x][y + 1] = 0;
                            columns[x][j] = false;
                            rows[y + 1][j] = false;
                            square[x / 3][(y + 1) / 3][j] = false;
                        }
                        if(!columns[x][j] && !rows[y][j] && !square[x / 3][y / 3][j]
                           && !columns[x][i] && !rows[y + 1][i] && !square[x / 3][(y + 1) / 3][i])
                        {
                            tiles[i][j] = true;
                            board[x][y] = j + 1;
                            columns[x][j] = true;
                            rows[y][j] = true;
                            square[x / 3][y / 3][j] = true;
                            board[x][y + 1] = i + 1;
                            columns[x][i] = true;
                            rows[y + 1][i] = true;
                            square[x / 3][(y + 1) / 3][i] = true;
                            dfs(index + 2);
                            tiles[i][j] = false;
                            board[x][y] = 0;
                            columns[x][j] = false;
                            rows[y][j] = false;
                            square[x / 3][y / 3][j] = false;
                            board[x][y + 1] = 0;
                            columns[x][i] = false;
                            rows[y + 1][i] = false;
                            square[x / 3][(y + 1) / 3][i] = false;
                        }
                    }
                }
            }
        }
    }
    else
    {
        dfs(index + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int i = 1;
    while(true)
    {
        int N; cin >> N;
        if(!N) break;
        cout << "Puzzle " << i++ << '\n';
        for(int j = 0; j < N; j++)
        {
            int U, V; string LU, LV;
            cin >> U >> LU >> V >> LV;
            int x = LU[0] - 'A';
            int y = LU[1] - '1';
            board[x][y] = U;
            columns[x][U - 1] = true;
            rows[y][U - 1] = true;
            square[x / 3][y / 3][U - 1] = true;
            x = LV[0] - 'A';
            y = LV[1] - '1';
            board[x][y] = V;
            columns[x][V - 1] = true;
            rows[y][V - 1] = true;
            square[x / 3][y / 3][V - 1] = true;
            tiles[U - 1][V - 1] = true;
            tiles[V - 1][U - 1] = true;
        }
        for(int j = 1; j <= 9; j++)
        {
            string s; cin >> s;
            int x = s[0] - 'A';
            int y = s[1] - '1';
            board[x][y] = j;
            columns[x][j - 1] = true;
            rows[y][j - 1] = true;
            square[x / 3][y / 3][j - 1] = true;
        }
        dfs(0);
        for(int j = 0; j < 9; j++)
        {
            for(int k = 0; k < 9; k++)
            {
                cout << answer[j][k];
            }
            cout << '\n';
        }
        for(int j = 0; j < 9; j++)
        {
            for(int k = 0; k < 9; k++)
            {
                board[j][k] = 0;
                columns[j][k] = false;
                rows[j][k] = false;
                tiles[j][k] = false;
                answer[j][k] = 0;
             }
        }
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                fill(square[j][k], square[j][k] + 9, false);
            }
        }
    }
    return 0;
}
