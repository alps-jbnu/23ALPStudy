#include<iostream>
#include<vector>
using namespace std;
int n,in_1,in_2;
vector<int> al[100001];
int pa[100001];
void dfs(int cur){
    for(int nxt:al[cur]){
        if(nxt==pa[cur])continue;
        pa[nxt]=cur;
        dfs(nxt);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>in_1>>in_2;
        al[in_1].push_back(in_2);
        al[in_2].push_back(in_1);
    }
    dfs(1);
    for(int i=2;i<=n;i++)
        cout<<pa[i]<<'\n';
}