#include <bits/stdc++.h>
#define pii pair<int, int>
const int MAX = 200000 + 1;
using namespace std;

int N, R;
int gidung_len, branch_len, n_start, n_end;
vector<pii> vec[MAX];
bool Visited[MAX];

void find_gidung(int node, int len)
{
    Visited[node] = 1;
    gidung_len = len;
    n_start = node;

    if (vec[node].size() > 2) return;

    for (auto next : vec[node])
    {
        if (!Visited[next.first])
        {
            Visited[next.first] = true;
            find_gidung(next.first, len + next.second);
        }
    }
}

void find_branch(int node, int len)
{
    Visited[node] = 1;

    if (len > branch_len)
    {
        branch_len = len;
        n_end = node;
    }

    for (auto next : vec[node])
    {
        if (!Visited[next.first])
        {
            Visited[next.first] = true;
            find_branch(next.first, len + next.second);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> R;
    for (int i = 0; i < N - 1; i++)
    {
        int a, b, d; cin >> a >> b >> d;

        vec[a].push_back({ b, d });
        vec[b].push_back({ a, d });
    }

    if (vec[R].size() >= 2)
    {
        find_gidung(R, 0);
        gidung_len = 0;

        memset(Visited, 0, sizeof(Visited));
        find_branch(R, 0);
    }
    else
    {
        find_gidung(R, 0);
        find_branch(n_start, 0);
    }

    cout << gidung_len << " " << branch_len;

    return 0;
}