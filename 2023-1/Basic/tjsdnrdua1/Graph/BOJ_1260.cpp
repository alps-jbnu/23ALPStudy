//연결그래프 아님: 연결 요소의 개수 찾기
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include <algorithm>

using namespace std;
int v,e,s_p;    //정점 개수, 엣지 개수,시작점
int v1,v2;  //입력으로 들어오는 두 정점

vector<int> adj[1002];    //adjacency list
bool vis[1002];

void bfs(int c){
    queue<int> q;
    q.push(c);
    vis[c]=true;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
            cout<<cur<<" ";
        for(auto nxt:adj[cur]){
            if(vis[nxt])continue;
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
        vis[cur]=true;          //방문표시
        cout<<cur<<" ";
        //★스택에 역순으로 삽입
        for(int i=0;i<(int)adj[cur].size();i++){
            int nxt=adj[cur][adj[cur].size()-1-i];
            if(vis[nxt])continue;
            s.push(nxt);
        }
    }
}
void dfs_r(int cur){    //재귀: 직관적이지만, 스택 비용 큼
    vis[cur]=true;
    cout<<cur<<" ";
    for(auto nxt:adj[cur]){
        if(vis[nxt])continue;
        dfs_r(nxt);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>v>>e>>s_p;
    while(e--){
        cin>>v1>>v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    //★인접리스트: 각 정점에 대해 번호 오름차순 정렬
    for(int i=1;i<=v;i++)
        sort(adj[i].begin(),adj[i].end());

//    dfs(s_p);
//    cout<<'\n';
//    fill(vis+1,vis+v+1,false);
    dfs_r(s_p);
    cout<<'\n';
    fill(vis+1,vis+v+1,false);
    bfs(s_p);

    return 0;
}
