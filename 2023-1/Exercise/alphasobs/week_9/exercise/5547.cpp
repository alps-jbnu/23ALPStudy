#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
#define pip pair<int, pii>
const int MAX = 100 + 10;
using namespace std;

int W, H, result = 0;
int arr[MAX][MAX];
int odd[6][2] = { {1,0},{1,1},{-1,0},{-1,1},{0,-1},{0,1} };
int even[6][2] = { {1,-1},{1,0},{-1,-1},{-1,0},{0,-1},{0,1} };
queue<pii> q;

int BFS(int a, int b)
{
    q.push({ a, b });

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(!(x % 2))
        {
            for(int i = 0; i < 6; i++)
            {
                int nx = x + even[i][0];
                int ny = y + even[i][1];

                if(nx >= 0 && nx <= H + 1 && ny >= 0 && ny <= W + 1)
                {
                    if(!arr[nx][ny])
                    {
                        q.push({ nx, ny });
                        arr[nx][ny] = -1;
                    }
                    else if(arr[nx][ny] == 1) result++;
                }
            }
        }
        else 
        {
            for(int i = 0; i < 6; i++)
            {
                int nx = x + odd[i][0];
                int ny = y + odd[i][1];

                if(nx >= 0 && nx <= H + 1 && ny >= 0 && ny <= W + 1)
                {
                    if(!arr[nx][ny])
                    {
                        q.push({ nx, ny });
                        arr[nx][ny] = -1;
                    }
                    else if(arr[nx][ny] == 1) result++;
                }
            }
        }
    }
    return result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> W >> H;
    for(int i = 1; i <= H; i++)
        for(int j = 1; j <= W; j++)
            cin >> arr[i][j];

    cout << BFS(0, 0);
    return 0;
}