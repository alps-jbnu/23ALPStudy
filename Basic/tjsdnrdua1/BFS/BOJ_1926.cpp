#include<bits/stdc++.h>  //iostream, deque, vector, utility(pair)
using namespace std;
#define X first
#define Y second
int board[502][502];
bool vis[502][502];
int n,m;
int ix,iy;              //initial x,y
int picCnt,maxArea;     //count pics, maxArea of the largest pic
int dx[4]={1,0,-1,0}; int dy[4]={0,1,0,-1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>board[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            if(board[i][j]&&!vis[i][j]){
                ix=i;iy=j;
                deque<pair<int,int>> Q;     //덱을 큐처럼 사용
                vis[ix][iy]=1;
                Q.push_back({ix,iy});
                int areaCnt=0;
                while(!Q.empty()){
                    pair<int,int>cur=Q.front(); Q.pop_front();
                    areaCnt++;
                    for(int dir=0;dir<4;dir++){
                        int nx=cur.X+dx[dir]; int ny=cur.Y+dy[dir];
                        if(nx<0||nx>=n||ny<0||ny>=m) continue;
                        if(vis[nx][ny]||!board[nx][ny]) continue;
                        vis[nx][ny]=1;
                        Q.push_back({nx,ny});
                    }
                }
                picCnt++;
                if(areaCnt>maxArea) maxArea=areaCnt;
            }
    }
    cout<<picCnt<<'\n'<<maxArea;
}
