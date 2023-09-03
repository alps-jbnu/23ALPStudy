#include<iostream>
//#include<queue>
using namespace std;
const int MX=100005;
int dist[MX];
void move(int pos,int mode,int& nx){
    if(mode==0) nx=pos+1;
    else if(mode==1) nx=pos-1;
    else if(mode==2) nx=pos*2;
}
template<typename T>
class Queue {
    int head;    int tail;
    T dat[MX];
public:
    Queue(T s)
            :head{0},tail{0}{
        dist[s]=0;
        this->push(s);
    }
    void push(T x) { dat[tail++]=x; }
    void pop(){ head++; }
    T front(){ return dat[head]; }
    bool empty(){ return head==tail; }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(dist,dist+MX,-1);

    int n,k;        //n: FJ, k:FC
    cin>>n>>k;      //5 17
    Queue<int> Q{n};    //dist[5]=0; Q.push(5);
    int cur=n;          //initial current position=5
    int nx;             //new position(x)
    while(!Q.empty()){
        cur=Q.front(); Q.pop();
        if(cur==k){       //Caught the cow
            cout<<dist[cur];
            return 0;
        }
        for(int i=0;i<3;i++){
            move(cur,i,nx);
            if(nx<0||nx>=MX) continue;
            if(dist[nx]!=-1) continue;
            dist[nx]=dist[cur]+1;
            Q.push(nx);
        }
    }
    cout<<0;
}