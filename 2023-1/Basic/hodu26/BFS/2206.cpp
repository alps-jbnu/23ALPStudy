#include <bits/stdc++.h>

using namespace std;

string mapp[1003];
int vis[1003][1003];
int dx[4] = {0, 0, 1,-1};
int dy[4] = {1,-1, 0, 0};

int go_bfs(int N, int M, pair<int,int> cur){
    queue<pair<int,int>> q;   // break 0 wall
    queue<pair<int,int>> qb;  // break 1 wall

    int nxt_x,nxt_y;
    int dist = 1;  // count start

    q.push(cur);
    vis[cur.first][cur.second] = true;

    int qsize = q.size();    // break 0 wall
    int qbsize = qb.size();  // break 1 wall
    int size = qsize + qbsize;

    while (!q.empty() || !qb.empty()){
        if (size > qbsize){
            cur = q.front(); q.pop();
        }
        else {
            cur = qb.front(); qb.pop();
        }

        if (cur.first == N-1 && cur.second == M-1){
            return dist;
        }

        for (int i=0;i<4;i++){
            nxt_x = cur.first + dx[i];
            nxt_y = cur.second + dy[i];

            if (0 <= nxt_x && nxt_x < N && 0 <= nxt_y && nxt_y < M){
                if (mapp[nxt_x][nxt_y] == '0' && size > qbsize && vis[nxt_x][nxt_y] != 1){  // break 0 wall
                    q.push(make_pair(nxt_x,nxt_y));                                         //-> 벽을 부순 후 지나간 자리도 고려해야함
                    vis[nxt_x][nxt_y] = 1;
                }
                else if (vis[nxt_x][nxt_y] == 0 && (mapp[nxt_x][nxt_y] == '0' || (mapp[nxt_x][nxt_y] == '1' && size > qbsize))){  // break 1 wall
                    qb.push(make_pair(nxt_x,nxt_y));
                    vis[nxt_x][nxt_y] = 2;
                }       
            }
        }

        size--;

        if (size == 0){
            qsize = q.size();    // break 0 wall
            qbsize = qb.size();  // break 1 wall
            size = qsize + qbsize;
            dist++;
        }
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N,M;

    cin >> N >> M;

    for (int i=0;i<N;i++){
        cin >> mapp[i];
    }

    cout << go_bfs(N,M,{0,0});

    return 0;
}
