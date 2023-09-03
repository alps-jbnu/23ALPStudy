#include <bits/stdc++.h>

using namespace std;

vector<int> v[3001];
bool check[3001];

void dfs(int x) {
    check[x] = true;
    for(int i = 0; i < v[x].size(); i++)
    {
        if(!check[v[x][i]])
            dfs(v[x][i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E; cin >> V >> E;
    for(int i = 0; i < E; i++)
    {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int component = 0;
    for(int i = 1; i <= V; i++)
    {
        if(!check[i])
        {
            dfs(i);
            component++;
        }
    }
    if(component > 1)
    {
        cout << "NO";
        return 0;
    }
    int cnt = 0;
    for(int i = 1; i <= V; i++)
    {
        if(v[i].size() % 2) cnt++;
    }
    if(cnt == 2 || cnt == 0)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
