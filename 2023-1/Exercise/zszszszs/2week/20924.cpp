#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> tree[200005];
bool visited[2000005];
int start_branch, trunk_len, branch_len, end_branch;

void find_trunk(int node, int len)
{
    visited[node] = true;
    start_branch = node;
    trunk_len = len;

    if (tree[node].size() > 2)
    {
        return;
    }
    for (auto next : tree[node])
    {
        if (!visited[next.first])
        {
            visited[next.first] = true;
            find_trunk(next.first, len + next.second);
        }
    }
}

void find_branch(int node, int len)
{
    visited[node] = true;
    if (len > branch_len)
    {
        end_branch = node;
        branch_len = len;
    }
    for (auto next : tree[node])
    {
        if (!visited[next.first])
        {
            visited[next.first] = true;
            find_branch(next.first, len + next.second);
        }
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, r;
    cin >> n >> r;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, d;
        cin >> a >> b >> d;
        tree[a].push_back({b, d});
        tree[b].push_back({a, d});
    }
    if (tree[r].size() >= 2)
    {
        find_trunk(r, 0);
        trunk_len = 0;
        fill(visited, visited + n + 1, 0);
        find_branch(r, 0);
    }
    else
    {
        find_trunk(r, 0);
        find_branch(start_branch, 0);
    }
    cout << trunk_len << ' ' << branch_len;
}