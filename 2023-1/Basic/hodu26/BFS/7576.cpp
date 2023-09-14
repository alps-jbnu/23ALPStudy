#include <bits/stdc++.h>

using namespace std;

int box[1003][1003];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

queue<pair<int,int>> q;

int tomato_bfs(int N, int M){
    pair<int,int> cur_loc,nxt_loc;
    int min_day = 0;

    int size = q.size();

    while(!q.empty()){
        cur_loc = q.front(); q.pop();
        size--;

        for (int i=0;i<4;i++){
            nxt_loc = make_pair(cur_loc.first+dy[i],cur_loc.second+dx[i]);

            if (0 <= nxt_loc.first && nxt_loc.first < N && 0 <= nxt_loc.second && nxt_loc.second < M && box[nxt_loc.first][nxt_loc.second] == 0){
                q.push(nxt_loc);
                box[nxt_loc.first][nxt_loc.second] = 1;
            }
        }

        if (size == 0){
            size = q.size();
            min_day++;
        }
    }

    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            if (box[i][j] == 0){
                return -1;
            }
        }
    }

    return min_day-1;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int N,M;

    cin >> M >> N;

    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cin >> box[i][j];

            if (box[i][j] == 1){
                q.push(make_pair(i,j));
            }
        }
    }

    cout << tomato_bfs(N,M);

    return 0;
}
