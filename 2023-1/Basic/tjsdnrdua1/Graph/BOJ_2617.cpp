#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
int n,m,u,v;
int ans;
vector<int> al_h[104],al_l[104];
bool vis[104];
bool isNotMiddle(const int& s, vector<int>* al){
    fill(vis+1,vis+n+1,false);
    queue<int> q;   q.push(s);
    vis[s]=true;
    int cnt=0;  //s보다 무겁거나 가벼운 구슬 개수
    while(!q.empty()){                  //bfs
        int cur=q.front();  q.pop();
        for(int nxt:al[cur]){
            if(vis[nxt])continue;
            q.push(nxt);
            vis[nxt]=true;
            cnt++;
        }
    }
    return cnt>=(n+1)/2;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    while(m--){
        cin>>u>>v;
        al_h[u].push_back(v);
        al_l[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        ans+=(isNotMiddle(i, al_h) || isNotMiddle(i, al_l));
    cout<<ans;
    return 0;
}