#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> v[101];
int vis[101];
int n,a;

void dfs(int);

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a;
            if(a) v[i].push_back(j);
        }
    }

    for(int i=0; i<n; i++){
        memset(vis, 0, sizeof(vis));
        dfs(i);

        for(int j=0; j<n; j++)
            cout<<vis[j]<<" ";
        cout<<"\n";
    }
}

void dfs(int x){
    for(int i=0; i<v[x].size(); i++){
        if(!vis[v[x][i]]){
            vis[v[x][i]]=1;
            dfs(v[x][i]);
        }
    }
}