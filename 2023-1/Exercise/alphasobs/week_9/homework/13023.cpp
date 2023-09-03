#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
#define pip pair<int, pii>
const int MAX = 2000 + 1;
using namespace std;

int N, M, flag = 0;
vector<int> vec[MAX];
bool Visited[MAX];

void DFS(int x, int y)
{
    if(y == 4)
    {
        flag = 1;
        return; 
    }
    Visited[x] = 1;

    for(int i = 0; i < vec[x].size(); i++)
    {
        int nx = vec[x][i];
        if(!Visited[nx] && !flag) DFS(nx, y + 1);
    }
    Visited[x] = 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for(int i = 0; i < N; i++)
    {
        DFS(i, 0);
        if(flag) break;
    }
    cout << flag;

    return 0;
}