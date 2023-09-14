#include<iostream>
#include<vector>
using namespace std;
int v;
vector<int> al[102];
bool vis[102];

void dfs(int x){
    for(int nxt : al[x]){
        if(!vis[nxt]){
            vis[nxt]=true;
            dfs(nxt);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>v;
    bool isConnected;
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            cin>>isConnected;
            //connect(`directed` link) ith node to jth node
            if(isConnected)
                al[i].push_back(j);
        }
    }
    for(int i=1;i<=v;i++){
        fill(vis+1,vis+v+1,false);
        dfs(i);
        for(int j=1;j<=v;j++)
            cout<<vis[j]<<" ";
        cout<<'\n';
    }
}