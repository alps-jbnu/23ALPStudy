#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int k,v,e,v1,v2;    //testcase, vertex, edge, vertex1 <-> vertex2
vector<int> al[20002];
int color[20002];
string dfs(){
    for(int i=1;i<=v;i++){
        if(color[i]!=-1)continue;
        stack<int> s;   s.push(i);
        color[i]=0;
        while(!s.empty()){
            int cur=s.top();    s.pop();
            for(int nxt:al[cur]){
                //방문한 적 있는 경우
                if(color[nxt]!=-1){
                    if(color[nxt]==color[cur])
                        return "NO\n";
                    continue;
                }
                //처음 방문하는 경우
                color[nxt]=(color[cur]+1)%2;
                s.push(nxt);
            }
        }
    }
    return "YES\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>k;
    while(k--){
        cin>>v>>e;
        for(int i=1;i<=v;i++)
            al[i].clear();
        fill(color+1,color+v+1,-1);
        while(e--){
            cin>>v1>>v2;
            al[v1].push_back(v2);
            al[v2].push_back(v1);
        }
        cout<<dfs();
    }
    return 0;
}