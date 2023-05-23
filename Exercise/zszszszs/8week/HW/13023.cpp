#include <bits/stdc++.h>
using namespace std;
bool ans = false;
vector<vector<int>> adj(2005);
void dfs(int depth, int cur, vector<bool> &vis)
{
    if (depth == 4)
    {

        ans = true;
        return;
    }

    for (int j = 0; j < adj[cur].size(); j++)
    {

        auto nxt = adj[cur][j];
        if (vis[nxt])
            continue;
        vis[nxt] = 1;
        dfs(depth + 1, nxt, vis);
        vis[nxt] = 0;
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        vector<bool> vis(2005);

        vis[i] = true;
        dfs(0, i, vis);

        if (ans)
            break;
    }
    cout << ans;
}