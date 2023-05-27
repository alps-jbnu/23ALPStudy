#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[32001];
int deg[32001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }

    //작은 번호 (쉬운 문제)부터 해결하기 위해 우선순위 큐 사용
    priority_queue<int, vector<int>, greater<int>> q;
    queue<int> ans;
    for(int i=1; i<=n; i++){
        if(deg[i]==0) q.push(i);
    }

    while(!q.empty()){
        int cur = q.top();
        q.pop();
        ans.push(cur);

        for(int nxt : adj[cur]){
            deg[nxt]--;
            if(deg[nxt]==0){
                q.push(nxt);
            }
        }
    }

    while(!ans.empty()){
        cout << ans.front() << " ";
        ans.pop();
    }
}
