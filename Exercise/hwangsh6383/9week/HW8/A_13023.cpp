#include <bits/stdc++.h>

using namespace std;

vector<int> fri[2001];
bool used[2001];

void dfs(int s, int c, bool& answer) {
    if(c == 4)
    {
        answer = true;
        return;
    }
    for(auto f : fri[s])
    {
        if(used[f])
            continue;
        used[s] = true;
        dfs(f, c + 1, answer);
        used[s] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        fri[a].push_back(b);
        fri[b].push_back(a);
    }
    bool answer = false;
    for(int i = 0; i < N; i++)
    {
        dfs(i, 0, answer);
        if(answer)
            break;
    }
    cout << answer;
    return 0;
}
