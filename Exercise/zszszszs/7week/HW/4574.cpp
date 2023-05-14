#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 9;

int N;
int sudoku[MAX][MAX];           // 스도쿠 판
bool visited[MAX + 1][MAX + 1]; // 이미 있는 타일 파악
bool col[MAX][MAX + 1];         // 세로
bool row[MAX][MAX + 1];         // 가로
bool square[3][3][MAX + 1];     // 3 * 3 칸
bool flag = false;

int calcIdx(int idx)
{
    return idx / 3;
}

void DFS(int idx)
{
    // 이미 답을 찾은 경우
    if (flag)
        return;

    if (idx == 81)
    {
        flag = true;
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
                cout << sudoku[i][j];
            cout << "\n";
        }
        return;
    }

    int y = idx / 9;
    int x = idx % 9;
    // 이미 해당 칸이 채워져있는 경우
    if (sudoku[y][x])
        DFS(idx + 1);
    else
    {
        // 가로로 채우는 경우
        if (x < 8 && !sudoku[y][x + 1])
        {
            for (int i = 1; i <= 9; i++)
                for (int j = i + 1; j <= 9; j++)
                    if (!visited[i][j]) // 해당 타일을 아직 안 썼고
                    {
                        visited[i][j] = true;
                        visited[j][i] = true;
                        // 두 가지 경우 파악
                        // 1. i j
                        if (!row[y][i] && !col[x][i] && !square[calcIdx(y)][calcIdx(x)][i])
                            if (!row[y][j] && !col[x + 1][j] && !square[calcIdx(y)][calcIdx(x + 1)][j])
                            {
                                row[y][i] = true;
                                col[x][i] = true;
                                square[calcIdx(y)][calcIdx(x)][i] = true;
                                row[y][j] = true;
                                col[x + 1][j] = true;
                                square[calcIdx(y)][calcIdx(x + 1)][j] = true;
                                sudoku[y][x] = i;
                                sudoku[y][x + 1] = j;
                                // idx + 1까지 채웠으므로
                                DFS(idx + 2);
                                // 다시 false
                                sudoku[y][x] = 0;
                                sudoku[y][x + 1] = 0;
                                row[y][i] = false;
                                col[x][i] = false;
                                square[calcIdx(y)][calcIdx(x)][i] = false;
                                row[y][j] = false;
                                col[x + 1][j] = false;
                                square[calcIdx(y)][calcIdx(x + 1)][j] = false;
                            }
                        // 2. j i
                        if (!row[y][j] && !col[x][j] && !square[calcIdx(y)][calcIdx(x)][j])
                            if (!row[y][i] && !col[x + 1][i] && !square[calcIdx(y)][calcIdx(x + 1)][i])
                            {
                                row[y][j] = true;
                                col[x][j] = true;
                                square[calcIdx(y)][calcIdx(x)][j] = true;
                                row[y][i] = true;
                                col[x + 1][i] = true;
                                square[calcIdx(y)][calcIdx(x + 1)][i] = true;
                                sudoku[y][x] = j;
                                sudoku[y][x + 1] = i;
                                // idx + 1까지 채웠으므로
                                DFS(idx + 2);
                                // 다시 false
                                sudoku[y][x] = 0;
                                sudoku[y][x + 1] = 0;
                                row[y][j] = false;
                                col[x][j] = false;
                                square[calcIdx(y)][calcIdx(x)][j] = false;
                                row[y][i] = false;
                                col[x + 1][i] = false;
                                square[calcIdx(y)][calcIdx(x + 1)][i] = false;
                            }

                        visited[i][j] = false;
                        visited[j][i] = false;
                    }
        }
        // 세로로 채우는 경우
        if (y < 8 && !sudoku[y + 1][x])
        {
            for (int i = 1; i <= 9; i++)
                for (int j = i + 1; j <= 9; j++)
                    if (!visited[i][j]) // 해당 타일을 아직 안 썼고
                    {
                        visited[i][j] = true;
                        visited[j][i] = true;
                        // 두 가지 경우 파악
                        // 1. i j
                        if (!row[y][i] && !col[x][i] && !square[calcIdx(y)][calcIdx(x)][i])
                            if (!row[y + 1][j] && !col[x][j] && !square[calcIdx(y + 1)][calcIdx(x)][j])
                            {
                                row[y][i] = true;
                                col[x][i] = true;
                                square[calcIdx(y)][calcIdx(x)][i] = true;
                                row[y + 1][j] = true;
                                col[x][j] = true;
                                square[calcIdx(y + 1)][calcIdx(x)][j] = true;
                                sudoku[y][x] = i;
                                sudoku[y + 1][x] = j;
                                // idx만 채웠으므로
                                DFS(idx + 1);
                                // 다시 false
                                sudoku[y][x] = 0;
                                sudoku[y + 1][x] = 0;
                                row[y][i] = false;
                                col[x][i] = false;
                                square[calcIdx(y)][calcIdx(x)][i] = false;
                                row[y + 1][j] = false;
                                col[x][j] = false;
                                square[calcIdx(y + 1)][calcIdx(x)][j] = false;
                            }
                        // 2. j i
                        if (!row[y][j] && !col[x][j] && !square[calcIdx(y)][calcIdx(x)][j])
                            if (!row[y + 1][i] && !col[x][i] && !square[calcIdx(y + 1)][calcIdx(x)][i])
                            {
                                row[y][j] = true;
                                col[x][j] = true;
                                square[calcIdx(y)][calcIdx(x)][j] = true;
                                row[y + 1][i] = true;
                                col[x][i] = true;
                                square[calcIdx(y + 1)][calcIdx(x)][i] = true;
                                sudoku[y][x] = j;
                                sudoku[y + 1][x] = i;
                                // idx까지 채웠으므로
                                DFS(idx + 1);
                                // 다시 false
                                sudoku[y][x] = 0;
                                sudoku[y + 1][x] = 0;
                                row[y][j] = false;
                                col[x][j] = false;
                                square[calcIdx(y)][calcIdx(x)][j] = false;
                                row[y + 1][i] = false;
                                col[x][i] = false;
                                square[calcIdx(y + 1)][calcIdx(x)][i] = false;
                            }

                        visited[i][j] = false;
                        visited[j][i] = false;
                    }
        }
    }
    return;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 1;
    while (1)
    {
        flag = false;
        memset(sudoku, 0, sizeof(sudoku));
        memset(visited, false, sizeof(visited));
        memset(col, false, sizeof(col));
        memset(row, false, sizeof(row));
        memset(square, false, sizeof(square));

        cin >> N;
        if (N == 0)
            break;

        // 전처리
        for (int i = 0; i < N; i++)
        {
            int U, V;
            string LU, LV;
            cin >> U >> LU >> V >> LV;

            // 해당 타일 씀
            visited[U][V] = true;
            visited[V][U] = true;

            int y1 = LU[0] - 'A';
            int x1 = LU[1] - '0' - 1;
            int y2 = LV[0] - 'A';
            int x2 = LV[1] - '0' - 1;
            // 숫자 표시
            sudoku[y1][x1] = U;
            sudoku[y2][x2] = V;
            // 가로, 세로 표시
            col[x1][U] = true;
            col[x2][V] = true;
            row[y1][U] = true;
            row[y2][V] = true;
            // 3 * 3 표시
            square[calcIdx(y1)][calcIdx(x1)][U] = true;
            square[calcIdx(y2)][calcIdx(x2)][V] = true;
        }

        for (int i = 1; i <= 9; i++)
        {
            string s;
            cin >> s;

            int y = s[0] - 'A';
            int x = s[1] - '0' - 1;
            sudoku[y][x] = i;
            // 가로 세로 표시
            row[y][i] = true;
            col[x][i] = true;
            // 3*3 표시
            square[calcIdx(y)][calcIdx(x)][i] = true;
        }

        cout << "Puzzle " << cnt++ << "\n";
        DFS(0);
    }
    return 0;
}