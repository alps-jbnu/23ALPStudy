#include <bits/stdc++.h>
using namespace std;

int n, m, r;
vector<int> v[100005];
bool vis[100005];
int ans[100005];

void dfs(int cur, int level)
{
    ans[cur] = level;
    vis[cur] = true;
    level++;
    for (int i = 0; i < v[cur].size(); i++)
    {
        if (vis[v[cur][i]] == false)
        {
            dfs(v[cur][i], level);
        }
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(v[i].begin(), v[i].end());
    }
    fill_n(ans, 100005, -1);
    dfs(r, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << '\n';
    }
}