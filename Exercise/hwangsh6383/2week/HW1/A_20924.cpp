#include <bits/stdc++.h>

using namespace std;

int LongestbranchLength = 0;
vector<pair<int,int>> tree[200001];
bool check[200001];

void dfs(int r, int length) {
    if(tree[r].size() == 1)
    {
        LongestbranchLength = max(LongestbranchLength, length);
        return;
    }
    for(int i = 0; i < tree[r].size(); i++)
    {
        if(check[tree[r][i].first]) continue;
        check[r] = true;
        dfs(tree[r][i].first, length + tree[r][i].second);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, R; cin >> N >> R;
    for(int i = 0; i < N - 1; i++)
    {
        int a, b ,d; cin >> a >> b >> d;
        tree[a].push_back(make_pair(b, d));
        tree[b].push_back(make_pair(a, d));
    }
    check[0] = true;
    tree[R].push_back(make_pair(0, 0));
    int pillarLength = 0;
    while(true)
    {
        int temp = R;
        if(tree[temp].size() != 2)
            break;
        for(int i = 0; i < 2; i++)
        {
            if(check[tree[temp][i].first]) continue;
            check[temp] = true;
            pillarLength += tree[temp][i].second;
            R = tree[temp][i].first;
        }
    }
    dfs(R, 0);
    cout << pillarLength << ' ' << LongestbranchLength;
    return 0;
}
