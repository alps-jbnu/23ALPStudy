#include <bits/stdc++.h>

using namespace std;

string maze[103];
bool vis[103][103];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int findWay_bfs(pair<int,int> wall){
    queue<pair<int,int>> q;
    pair<int,int> cur_loc,nxt_loc, wall_ = {0,0};
    pair<int,int> flag = make_pair(wall.first-1,wall.second-1);
    int short_way = 1;

    q.push(make_pair(0,0));
    vis[0][0] = true;

    int size = q.size();

    while(!q.empty()){
        cur_loc = q.front(); q.pop();
        size--;

        if (cur_loc == flag){
            return short_way;
        }

        for (int i=0;i<4;i++){
            nxt_loc = make_pair(cur_loc.first+dy[i],cur_loc.second+dx[i]);

            if (wall_ <= nxt_loc && nxt_loc < wall && maze[nxt_loc.first][nxt_loc.second] == '1' && !vis[nxt_loc.first][nxt_loc.second]){
                q.push(nxt_loc);
                vis[nxt_loc.first][nxt_loc.second] = true;
            }
        }

        if (size == 0){
            size = q.size();
            short_way++;
        }
    }

    return short_way;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int N,M;

    cin >> N >> M;

    for (int i=0;i<N;i++){
        cin >> maze[i];
    }

    cout << findWay_bfs({N,M});

    return 0;
}
