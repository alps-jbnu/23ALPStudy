#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> edge[3005];
int vis[3005][3005];
bool chk = false;

void dfs(int cur, int id, int level)
{

    if (level == m)
    {
        chk = true;
    }
    for (int i = 0; i < edge[cur].size(); i++)
    {
        if (vis[cur][edge[cur][i]] == id)
            continue;
        vis[cur][edge[cur][i]] = id;
        vis[edge[cur][i]][cur] = id;
        dfs(edge[cur][i], id, level + 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(i, i, 0);
        if (chk == true)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}