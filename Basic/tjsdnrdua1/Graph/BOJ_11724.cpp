//연결그래프 아님: 연결 요소의 개수 찾기
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int v,e;    //정점 개수, 엣지 개수
int v1,v2;  //입력으로 들어오는 두 정점
int ans=0;

vector<int> adj[1002];    //adjacency list
bool vis[1002];

void bfs(){
    queue<int> q;
    for(int i=1;i<=v;i++){
        if(vis[i])continue;
        ans++;
        q.push(i);
        vis[i]=true;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
//            cout<<cur<<" ";
            for(auto nxt:adj[cur]){
                if(vis[nxt])continue;
                q.push(nxt);
                vis[nxt]=true;
            }
        }
    }
}
void dfs(int c){     //비재귀v1: 스택에 삽입하면서 방문체크
    stack<int> s;
    if(vis[c]) return;
    s.push(c);
    vis[c]=true;
    while(!s.empty()){
        int cur=s.top();
        s.pop();
//            cout<<cur<<" ";
        for(auto nxt:adj[cur]){
            if(vis[nxt])continue;
            s.push(nxt);
            vis[nxt]=true;
        }
    }
}
void dfs_n(int c){   //비재귀v2: 실제로 방문할 때 방문체크
    stack<int> s;
    if(vis[c])return;
    s.push(c);
    while(!s.empty()){  //스택에 많이 쌓이기는 하지만, 직관적
        int cur=s.top();
        s.pop();
        if(vis[cur])continue;   //실제로 방문할 때
        vis[cur]=true;          //방문표시
//            cout<<cur<<" ";
        for(auto nxt:adj[cur]){
            if(vis[nxt])continue;
            s.push(nxt);
        }
    }
}
void dfs_r(int cur){    //재귀: 직관적이지만, 스택 비용 큼
    vis[cur]=true;
//    cout<<cur<<" ";
    for(auto nxt:adj[cur]){
        if(vis[nxt])continue;
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

    bfs();        //BOJ_11724 제출번호: 60162641
//    for(int i=1;i<=v;i++) {
//        if(vis[i])continue;
//        ans++;
//        dfs(i);   //BOJ_11724 제출번호: 60163435
//        dfs_n(i);   //BOJ_11724 제출번호: 60163443
//        dfs_r(i);     //BOJ_11724 제출번호: 60162736
//    }
    cout<<ans;
    return 0;
}