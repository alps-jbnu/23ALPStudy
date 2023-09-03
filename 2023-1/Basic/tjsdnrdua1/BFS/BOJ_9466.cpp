//T(n)=n^2 -> 2*n -> `n`
#include <iostream>
using namespace std;
int t,n,arr[100004];
int state[100004];

const int NOT_VISITED=0;
const int IN_CYCLE=-1;

void run(int x){
    int cur=x;
    while(true){
        state[cur]=x;   //mark as visited: `매번 다른 값 대입`
        cur=arr[cur];   //move
        //case1: `이번`에 이미 방문
        if(state[cur]==x){
            while(state[cur]!=IN_CYCLE){    //IN_CYCLE인 node 만날 때까지
                state[cur]=IN_CYCLE;        //해당 node에 IN_CYCLE임을 체크
                cur=arr[cur];               //move
            }
            return;
        }
            //case2: `이전`에 이미 방문
        else if(state[cur]!=NOT_VISITED) return;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        fill(state+1,state+n+1,0);  //reset for each tc
        for(int i=1;i<=n;i++)
            cin>>arr[i];
        for(int i=1;i<=n;i++)
            if(state[i]==NOT_VISITED) run(i);   //n개의 노드에 대해 bfs? 돌리기
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(state[i]!=IN_CYCLE) cnt++;   //사이클 아닌 node 세기
        cout<<cnt<<'\n';
    }
    return 0;
}