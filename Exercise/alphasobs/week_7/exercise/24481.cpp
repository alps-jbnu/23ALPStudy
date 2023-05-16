#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
#define pip pair<int, pii>
const int MAX = 100000 + 1;
using namespace std;

ll N, M, R;
int Visited[MAX];
vector<int> vec[MAX];

void DFS(int x, int cnt)
{
    Visited[x] = cnt;
    for(int i = 0; i < vec[x].size(); i++)
    {
        int cx = vec[x][i];
        if(Visited[cx] != -1) continue;
        DFS(cx, cnt + 1);
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> N >> M >> R;
    for(int i = 0; i < M; i++)
    {
        int x, y; cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    
    for(int i = 1; i <= N; i++)
    {
        sort(vec[i].begin(), vec[i].end());
    }
    memset(Visited, -1, sizeof(Visited));
    DFS(R, 0);

    for(int i = 1; i <= N; i++)
    {
        cout << Visited[i] << "\n";
    }

	return 0;
}