// 구현 발상은 했지만 구현 능력이 딸려서 못 푼문제
// 방학때 다시 풀 것.
// https://yabmoons.tistory.com/495

#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
struct FISH
{
    int x;
    int y;
    int Dir;
    bool Live;
};

FISH fish[20];
int ans;
int board[4][4];
void Copy_State(int A[][4], int B[][4], FISH C[], FISH D[])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            A[i][j] = B[i][j];
        }
    }
    for (int i = 1; i <= 16; i++)
        C[i] = D[i];
}
void Swap_Fish(int Idx, int IIdx)
{
    /* 물고기들 끼리 자리를 바꾸는 경우 물고기들의 좌표를 바꿔주는 함수. */
    FISH Temp = fish[Idx];
    fish[Idx].x = fish[IIdx].x;
    fish[Idx].y = fish[IIdx].y;
    fish[IIdx].x = Temp.x;
    fish[IIdx].y = Temp.y;
}

void Move_Fish()
{
    for (int i = 1; i <= 16; i++)
    {
        if (fish[i].Live == false)
            continue;

        int x = fish[i].x;
        int y = fish[i].y;
        int Dir = fish[i].Dir;

        int nx = x + dx[Dir];
        int ny = y + dy[Dir];
        bool Flag = false;
        if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4)
        {
            if (board[nx][ny] == 0)
            {
                Flag = true;
                fish[i].x = nx;
                fish[i].y = ny;
                board[nx][ny] = i;
                board[x][y] = 0;
            }
            else if (board[nx][ny] != -1)
            {
                Flag = true;
                Swap_Fish(i, board[nx][ny]);
                swap(board[x][y], board[nx][ny]);
            }
        }

        if (Flag == false)
        {
            int nDir = Dir + 1;
            if (nDir == 9)
                nDir = 1;
            int nx = x + dx[nDir];
            int ny = y + dy[nDir];

            while (nDir != Dir)
            {
                if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4)
                {
                    if (board[nx][ny] == 0)
                    {
                        fish[i].x = nx;
                        fish[i].y = ny;
                        board[nx][ny] = i;
                        board[x][y] = 0;
                        fish[i].Dir = nDir;
                        break;
                    }
                    else if (board[nx][ny] != -1)
                    {
                        Swap_Fish(i, board[nx][ny]);
                        swap(board[x][y], board[nx][ny]);
                        fish[i].Dir = nDir;
                        break;
                    }
                }
                nDir++;
                if (nDir == 9)
                    nDir = 1;
                nx = x + dx[nDir];
                ny = y + dy[nDir];
            }
        }
    }
}
void Make_State(int x, int y, int nx, int ny, int Fish_Num, bool T)
{
    /* 상태를 바꾸거나 되돌리는 과정을 표현한 함수. */
    if (T == true)
    {
        board[x][y] = 0;
        board[nx][ny] = -1;
        fish[Fish_Num].Live = false;
    }
    else
    {
        board[x][y] = -1;
        board[nx][ny] = Fish_Num;
        fish[Fish_Num].Live = true;
    }
}
void DFS(int x, int y, int Dir, int Sum)
{
    /* 물고기의 움직임 + 상어의 움직임을 나타내는 DFS 함수. */

    ans = max(ans, Sum);
    /* 현재 상태를 임시 변수를 선언해서 저장해 주기. */
    int C_MAP[4][4];
    FISH C_Fish[20];
    Copy_State(C_MAP, board, C_Fish, fish);
    /*=========================================*/
    /* 물고기를 움직여주기 + 상어를 움직여주기 */
    Move_Fish();

    for (int i = 1; i <= 3; i++)
    {
        int nx = x + dx[Dir] * i;
        int ny = y + dy[Dir] * i;
        if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4)
        {
            if (board[nx][ny] == 0)
                continue;

            int Fish_Num = board[nx][ny];
            int nDir = fish[Fish_Num].Dir;

            Make_State(x, y, nx, ny, Fish_Num, true);
            DFS(nx, ny, nDir, Sum + Fish_Num);
            Make_State(x, y, nx, ny, Fish_Num, false);
        }
        else
            break;
    }
    /*==========================================*/
    Copy_State(board, C_MAP, fish, C_Fish);
    /* 최종적으로 다시 원래의 상태로 되돌려 놓기. */
}
void Solution()
{
    /* 초기 세팅. 상어가 (0, 0)에 있는 물고기를 잡아먹는다. */
    int F_Num = board[0][0];
    int Dir = fish[F_Num].Dir;
    fish[F_Num].Live = false;
    board[0][0] = -1;
    /*================================================*/
    DFS(0, 0, Dir, F_Num);
    cout << ans << endl;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num;
    int dir;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int num;
            int dir;
            cin >> num >> dir;
            board[i][j] = num;
            fish[num] = {i, j, dir, true};
        }
    }
    int F_Num = board[0][0];
    int Dir = fish[F_Num].Dir;
    fish[F_Num].Live = false;
    board[0][0] = -1;
    DFS(0, 0, Dir, F_Num);
    cout << ans << endl;
}