#include <bits/stdc++.h>

using namespace std;

vector<int> friends[53]; // adjacency list 인접 리스트
bool vis[53];

int score[53];

queue<int> q;

void check_bfs(int i){
    int size = q.size();

    while (!q.empty()){
        int cur = q.front(); q.pop();
        size--;

        for (int nxt : friends[cur]){
            if (!vis[nxt]){
                q.push(nxt);
                vis[nxt] = true;
            }
        }

        if (size == 0){
            size = q.size();
            score[i]++;
        }
    }

    return ;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,a,b, minScore=53;

    cin >> n;

    while(1){
        cin >> a >> b;

        if (a == b && b == -1) break;

        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    for (int i=1;i<=n;i++){
        q.push(i);
        vis[i] = true;
        check_bfs(i);

        fill(vis+1,vis+n+1,false);

        if (minScore > score[i]){
            minScore = score[i];
        }
    }

    vector<int> ans;
    for (int i=1;i<=n;i++){
        if (score[i] == minScore){
            ans.push_back(i);
        }
    }

    cout << minScore-1 << ' ' << ans.size() << '\n';
    for (int i : ans){
        cout << i << ' ';
    }

    return 0;
}
