#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int n,m, d[102][102];
bool visit[102][102];
const int INF = 0x3f3f3f3f;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int func(){
    for(int i = 1; i <= n; i++)
        fill(d[i] + 1, d[i] + m + 1, INF);

    priority_queue<tuple<int,int,int>, 
                    vector<tuple<int,int,int>>, greater<tuple<int,int,int>> > pq;
    d[1][1] = 0;
    pq.push({0,1,1});

    while(!pq.empty()){
        int cw,cx,cy;
        tie(cw,cx,cy) = pq.top();
        pq.pop();

        if(d[cx][cy] != cw) continue;

        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx > n || nx < 1) continue;
            if(ny > m || ny < 1) continue;

            int nw = cw + visit[nx][ny];
            if(nw < d[nx][ny]){
                d[nx][ny] = nw;
                pq.push({nw,nx,ny});
            }
        }
    }
    return d[n][m];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for(int i = 1; i <= n; i++){
        string str; 
        cin >> str;
        
        for(int j = 1; j <= m; j++)
            visit[i][j] = str[j-1] - '0';
    }
        
    cout << func();
}
