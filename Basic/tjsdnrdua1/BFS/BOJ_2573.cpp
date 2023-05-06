#include<iostream>
#include<queue>
#include<utility>
using namespace std;
#define X first
#define Y second

int n,m,year;
int area[303][303]; //sea: 0, ice: write height
bool vis[303][303];

int dx[]={1,0,-1,0}; int dy[]={0,1,0,-1};

void initvis(){ //initialize vis[][] annually
    for(int i=0;i<n;i++) fill(vis[i],vis[i]+m,false);
}

void melting(){
    //count `0`(water) area among 4 adjacent areas of each ice elements
    int zero[303][303]={};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(area[i][j]==0)continue;  //sea
            for(int d=0;d<4;d++){
                int nx=i+dx[d];int ny=j+dy[d];
                if(nx<0||nx>=n||ny<0||ny>=m) continue;  //RangeCheck
                if(area[nx][ny]!=0) continue;   //adjacent area is ice
                zero[i][j]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //area[][]>=0  --> redefine next year's ice height
            area[i][j]=max(0,area[i][j]-zero[i][j]);
        }
    }
}

int status(){
    int cnt1=0;
    int x=-1,y=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(area[i][j]){
                x=i;y=j;    //choose any area of ice
                cnt1++;     //count total ice area
            }
        }
    }
    if(cnt1==0) return 0;   //case#1: ALL melted
    int cnt2=0;
    queue<pair<int,int>> q;
    vis[x][y]=true;     //i.c.
    q.emplace(x,y);
    while(!q.empty()){
        pair<int,int> cur=q.front(); q.pop();
        cnt2++;
        for(int d=0;d<4;d++){
            int nx=cur.X+dx[d]; int ny=cur.Y+dy[d];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;//1.RangeCheck
            if(vis[nx][ny]) continue;//2.visitCheck
            if(area[nx][ny]<=0) continue;//3.isIceCheck
            vis[nx][ny]=true;
            q.emplace(nx,ny);
        }
    }
    if(cnt1==cnt2) return 1;    //case#2: Still 1 set
    return 2;       //case#3: Seperated!
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>area[i][j];
    }

    while(true){
        year++;
        melting();
        initvis();
        int check=status();
        if(check==0){    //FOREVER 1 set
            cout<<0;
            return 0;
        }
        else if(check==1)continue;   //still 1 set: not seperated YET
        else break;     //Seperated!
    }
    cout<<year;

    return 0;
}