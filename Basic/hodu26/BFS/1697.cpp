#include <bits/stdc++.h>

using namespace std;

bool vis[100003];

int find_bfs(int N, int K){
    int cur_loc, time = 0;
    int nxt_loc[3];

    queue<int> q;

    q.push(N);
    vis[N] = true;

    int size = q.size();

    while(!q.empty()){
        cur_loc = q.front(); q.pop();
        size--;

        if (cur_loc == K){
            return time;
        }

        nxt_loc[0] = cur_loc-1;
        nxt_loc[1] = cur_loc+1;
        nxt_loc[2] = 2*cur_loc;

        for (int i=0;i<3;i++){

            if (0 <= nxt_loc[i] && nxt_loc[i] <= 100001 && vis[nxt_loc[i]] == false){
                q.push(nxt_loc[i]);
                vis[nxt_loc[i]] = true;
            }
        }

        if (size == 0){
            size = q.size();
            time++;
        }
    }

    return time;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int N,K;

    cin >> N >> K;

    cout << find_bfs(N,K);

    return 0;
}
