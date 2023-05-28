#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[10001];
int deg[10001];
int result[10002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    int time[10001];
    for(int i=1; i<=n; i++){
        int num; 
        cin >> time[i] >> num; // 작업 시간, 작업 개수

        for(int j=1; j<=num; j++){
            int pre;
            cin >> pre;
            adj[pre].push_back(i); 
            deg[i]++;
        }
    }

    queue<int> q;
    for(int i=1; i<=n; i++){
        if(deg[i]==0) q.push(i);
        result[i] = time[i]; // 자기 작업시간으로 초기화
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int nxt : adj[cur]){
            deg[nxt]--;
            
            // 다음 작업시간 = 총 작업시간 + 다음 작업시간
            result[nxt] = max(result[nxt],result[cur]+time[nxt]); 
            
            if(deg[nxt]==0){
                q.push(nxt);
            }
        }
    }

    // 가장 큰 result 속 값이 총 작업시간
    int ans=0;
    for(int i=1; i<=n; i++){
        ans = max(ans,result[i]);
    }

    cout << ans;
}
