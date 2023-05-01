#include<iostream>
#include<queue>
using namespace std;
const int MX=200003;
int dist[MX];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(dist,dist+MX,-1);

    int n,k;
    cin>>n>>k;
    dist[n]=0;
    queue<int> Q;
    Q.push(n);
    while(dist[k]==-1){ //iterate til reach target(k)
        int cur=Q.front(); Q.pop();
        for(int nx:{cur*2,cur-1,cur+1}){
            if(nx==cur*2){   //time of teleportation=0
                //should be considered earlier than cur-1,cur+1
                if(nx<0||nx>=MX) continue;
                if(dist[nx]!=-1) continue;
                dist[nx]=dist[cur];
                Q.push(nx);

            }
            else {      //walking time=0
                if(nx<0||nx>=MX) continue;
                if(dist[nx]!=-1) continue;
                dist[nx]=dist[cur]+1;
                Q.push(nx);
            }
        }
    }
    cout<<dist[k];
}