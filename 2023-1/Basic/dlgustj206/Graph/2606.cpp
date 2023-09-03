#include <iostream>
#include <vector>
using namespace std;

vector<int> comp[101];
int vis[101];
int v, e, a, b;
int cnt=0;

void dfs(int);

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>v>>e;
    while(e--){
        cin>>a>>b;
        comp[a].push_back(b);
        comp[b].push_back(a);
    }
    dfs(1);
    cout<<cnt<<'\n';
}

void dfs(int x){
    vis[x]=1;
    for(int i=0; i<comp[x].size(); i++){
        int y=comp[x][i];
        if(!vis[y]){
            dfs(y);
            cnt++;
        }
    }
}