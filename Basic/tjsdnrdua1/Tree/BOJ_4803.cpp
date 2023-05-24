#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int v,e,e1,e2;
int tc,ans;
vector<int> al[505];
bool vis[505];
bool isTree;
void dfs(int cur,int prev){
    for(int nxt:al[cur]){
        if(nxt==prev) continue;
        if(vis[nxt]){
            isTree=0;
            continue;
        }
        vis[nxt]=1;
        dfs(nxt,cur);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        cin>>v>>e;
        if(v==0&&e==0) return 0;
        tc++;   ans=0;  //count testcase & init ans,vis,al
        fill(vis+1,vis+v+1,0);
        for(int i=1;i<=v;i++) al[i].clear();
        while(e--){
            cin>>e1>>e2;
            al[e1].push_back(e2);
            al[e2].push_back(e1);
        }
        for(int i=1;i<=v;i++){
            if(vis[i])continue;
            vis[i]=1;
            isTree=1;
            dfs(i,0);
            ans+=isTree;
        }
        cout<<"Case "<<tc<<": ";
        if(ans>1)cout<<"A forest of "<<ans<<" trees.\n";
        else if(ans==1){
            cout<<"There is one tree.\n";
        }else cout<<"No trees.\n";
    }
}