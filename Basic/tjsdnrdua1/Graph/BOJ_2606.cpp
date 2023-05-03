//다음 컴퓨터 방문할 때마다 정답 1씩 증가
#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;
int v,e;    //정점 개수, 엣지 개수
int v1,v2;  //입력으로 들어오는 두 정점
int ans;

vector<int> adj[102];    //adjacency list
bool vis[102];

void bfs(int c){
    queue<int> q;
    q.push(c);
    vis[c]=true;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
//        cout<<cur<<" ";
        for(auto nxt:adj[cur]){
            if(vis[nxt])continue;
            ans++;
            q.push(nxt);
            vis[nxt]=true;
        }
    }
}
void dfs(int c){   //비재귀: 실제로 방문할 때 방문체크
    stack<int> s;
    s.push(c);
    while(!s.empty()){  //스택에 많이 쌓이기는 하지만, 직관적
        int cur=s.top();
        s.pop();
        if(vis[cur])continue;   //실제로 방문할 때
        ans++;
        vis[cur]=true;          //방문표시
//        cout<<cur<<" ";
        for(auto nxt:adj[cur]){
            if(vis[nxt])continue;
            s.push(nxt);
        }
    }
    ans--;  //1번 컴퓨터까지 포함된 개수라서 1 감소
}
void dfs_r(int cur){    //재귀: 직관적이지만, 스택 비용 큼
    vis[cur]=true;
//    cout<<cur<<" ";
    for(auto nxt:adj[cur]){
        if(vis[nxt])continue;
        ans++;
        dfs_r(nxt);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>v>>e;
    while(e--){
        cin>>v1>>v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

//    dfs(1);
    dfs_r(1);
//    bfs(1);
    cout<<ans;
    return 0;
}