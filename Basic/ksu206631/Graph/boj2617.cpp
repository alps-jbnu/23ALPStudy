#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

#define red 1
#define blue 2

vector<int> v[20001];
int vis[20001];
int V,E;

void BFS(int s){
    vis[s] = red;
    queue<int> q;
    q.push(s);
    
    while(q.size()!=0)//큐가 빌 때까지 반복해주기
    {
        int n = q.front();
        q.pop();
        for(int i =  0; i<v[n].size(); i++){
            if(vis[v[n][i]]==0){
                q.push(v[n][i]);
                if(vis[n]==red) vis[v[n][i]] = blue;
                else if(vis[n]==blue) vis[v[n][i]] = red;
                    
                    
                
            }
        }
        
    }
}
bool check(){
    for(int i =1; i<=V; i++){
        for(int j = 0; j<v[i].size(); j++){
            if(vis[i]==vis[v[i][j]])
                return false;
        }
    }
    return true;
}

int main(){
    int k,u,a;
    cin >> k;
    while(k--){
        cin >> V >> E;
        for(int i = 0; i< E; i++){
            cin >> u >> a;
            v[u].push_back(a);
            v[a].push_back(u);
            
        }
        for(int i = 1; i<=V; i++){
            if(vis[i]==0){
                BFS(i);
            }
        }
        if(check())
            cout<<"YES\n";
        else
            cout << "NO\n";
        memset(vis, 0, sizeof(vis));
        memset(v, 0, sizeof(v));
    }
    
}
