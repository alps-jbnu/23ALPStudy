#include<iostream>
#include<queue>

#define MAX 200
using namespace std;
 
int W, H, K;
int MAP[MAX][MAX];
bool Visit[MAX][MAX][31];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int hdx[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int hdy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin >> K;
    cin >> W >> H;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> MAP[i][j];
        }
    }
  
  queue<pair<pair<int, int>, pair<int, int>>> Q;
    Q.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
    Visit[0][0][0] = true;
 
    while (Q.empty() == 0)
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int Cnt = Q.front().second.first;
        int Ability = Q.front().second.second;
        Q.pop();
 
        if (x == H - 1 && y == W - 1)
        {
            cout << Cnt << '\n';
            return;
        }
        if (Ability < K)
        {
            for (int i = 0; i < 8; i++)
            {
                int nx = x + hdx[i];
                int ny = y + hdy[i];
                if (nx >= 0 && ny >= 0 && nx < H && ny < W)
                {
                    if (MAP[nx][ny] == 0 && Visit[nx][ny][Ability + 1] == false)
                    {
                        Visit[nx][ny][Ability + 1] = true;
                        Q.push(make_pair(make_pair(nx, ny), make_pair(Cnt + 1, Ability + 1)));
                    }
                }
            }
        }
 
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx >= 0 && ny >= 0 && nx < H && ny < W)
            {
                if (MAP[nx][ny] == 0 && Visit[nx][ny][Ability] == false)
                {
                    Visit[nx][ny][Ability] = true;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(Cnt + 1, Ability)));
                }
            }
        }
    }
    cout << -1 << '\n';
 
    return 0;
}
