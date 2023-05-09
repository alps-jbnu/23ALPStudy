#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int v,v1,v2;
vector<int> al[52];
int ans[52];    //각 회원별 `가장 멀리 있는 회원까지의 길이` 저장

void bfs(int s){
    if(al[s].empty()) {
        ans[s] = 0x7f7f7f7f;    //아무 회원과도 친구가 아닌 경우 매우 큰 수 저장하고
        return;                 //반환
    }
    int dist[52];
    fill(dist+1,dist+v+1,-1);

    queue<int> q;   q.push(s);        //enqueue
    dist[s]=0;                          //mark as visited
    while(!q.empty()){
        int cur=q.front(); q.pop();     //dequeue
        for(auto nxt:al[cur]){
            if(dist[nxt]!=-1)continue;
            q.push(nxt);              //enqueue
            dist[nxt]=dist[cur]+1;      //mark as visited

            ans[s]=dist[nxt];           //renew ans[]
        }
    }
}
void display(){             //print result
    //점수 출력
    int MIN=ans[1];
    for(int i=2;i<=v;i++){
        if(ans[i]<MIN)
            MIN=ans[i];
    }
    cout<<MIN<<" ";
    //후보 수 출력
    int candcnt=0;
    for(int i=1;i<=v;i++)
        if(ans[i]==MIN)
            candcnt++;
    cout<<candcnt<<'\n';
    //후보 출력
    for(int i=1;i<=v;i++) {
        if (ans[i] == MIN&&candcnt!=1) {   //not last candidate
            candcnt--;
            cout << i << ' ';
        }else if(ans[i]==MIN&&candcnt==1)  //last candidate
            cout<<i;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>v;
    while(true){
        cin>>v1>>v2;
        if(v1==-1&&v2==-1)
            break;
        al[v1].push_back(v2);
        al[v2].push_back(v1);
    }

    for(int i=1;i<=v;i++)
        bfs(i);

    display();
    return 0;
}