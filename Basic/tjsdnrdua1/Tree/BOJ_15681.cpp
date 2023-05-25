#include<iostream>
#include<vector>
const int MX=100005;
using namespace std;
int N,R,Q,U,V,query;
vector<int> al[MX],vis(MX);
int Size[MX];
int dfs(int cur){
    vis[cur]=1;
    for(int nxt:al[cur]){
        if(vis[nxt])continue;
        Size[cur]+=dfs(nxt);
    }
    Size[cur]++;
    return Size[cur];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>R>>Q;
    for(int i=1;i<N;i++){
        cin>>U>>V;
        al[U].push_back(V);
        al[V].push_back(U);
    }
    dfs(R);
    while(Q--){
        cin>>query;
        cout<<Size[query]<<'\n';
    }
}