#include <bits/stdc++.h>

using namespace std;

int sea[303][303];
int visM[303][303];
int visI[303][303];
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};

void do_bfs(int N, int M, pair<int,int> cur, int day, char order){
    queue<pair<int,int>> q;

    int nxt_x,nxt_y;

    q.push(cur);
    if (order == 'M'){
        visM[cur.first][cur.second] = day;
    }
    else {
        visI[cur.first][cur.second] = day;
    }

    while (!q.empty()){
        cur = q.front(); q.pop();

        for (int i=0;i<4;i++){
            nxt_x = cur.first + dx[i];
            nxt_y = cur.second + dy[i];

            if (0 <= nxt_x && nxt_x < N && 0 <= nxt_y && nxt_y < M){
                if (order == 'M' && visM[nxt_x][nxt_y] < day){       // melt iceberg
                    if (sea[nxt_x][nxt_y] <= 0){
                        sea[cur.first][cur.second] -= 1;
                    }
                    else {
                        q.push(make_pair(nxt_x,nxt_y));
                        visM[nxt_x][nxt_y] = day;
                    }
                }
                else if (order == 'I' && sea[nxt_x][nxt_y] > 0 && visI[nxt_x][nxt_y] < day){   // check iceberg
                    q.push(make_pair(nxt_x,nxt_y));
                    visI[nxt_x][nxt_y] = day;
                }
            }
        }
    }

    return ;
}

void melt_iceberg_bfs(int N, int M, pair<int,int> cur, int day){
    return do_bfs(N,M,cur,day,'M');
}

void check_iceberg_bfs(int N, int M, pair<int,int> cur, int day){
    return do_bfs(N,M,cur,day,'I');
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N,M,iceberg, days=0;

    cin >> N >> M;

    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cin >> sea[i][j];
        }
    }

    while (true){
        days ++;

        for (int i=0;i<N;i++){
            for (int j=0;j<M;j++){
                if (sea[i][j] > 0 && visM[i][j] < days){
                    melt_iceberg_bfs(N,M,{i,j},days);
                    break;
                }
            }
        }

        iceberg = 0;
        for (int i=0;i<N;i++){
            for (int j=0;j<M;j++){
                if (sea[i][j] > 0 && visI[i][j] < days){
                    iceberg++;
                    if (iceberg > 1){  // more than one icebreg
                        cout << days;
                        return 0;
                    }
                    check_iceberg_bfs(N,M,{i,j},days);
                }
            }
        }

        if (iceberg == 0){  // no iceberg
            cout << 0;
            return 0;
        }
    }

    return 0;
}
