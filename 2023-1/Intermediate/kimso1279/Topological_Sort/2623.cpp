#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[32001];
vector<int> ans;
int deg[32001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int num;
        cin >> num;

        int pre;
        cin >> pre;
        while(--num){
            int cur;
            cin >> cur;
            adj[pre].push_back(cur);
            deg[cur]++;
            pre = cur;
        }
    }

    queue<int> q;

    for(int i=1; i<=n; i++){
        if(deg[i]==0) q.push(i);
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ans.push_back(cur);

        for(int nxt : adj[cur]){
            deg[nxt]--;
            if(deg[nxt]==0) q.push(nxt);
        }
    }

    if(ans.size() != n) cout << 0;
    else{
        for(auto s : ans) cout << s << endl;
    }
} 
