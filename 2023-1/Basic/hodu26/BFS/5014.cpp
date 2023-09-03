#include <bits/stdc++.h>

using namespace std;


bool vis[1000003];

int elv_bfs(int F, int cur, int G, int U, int D){
    queue<int> q;

    int nxt;
    int move = 0;

    q.push(cur);
    vis[cur] = true;

    int size = q.size();

    while (!q.empty()){
        cur = q.front(); q.pop();
        size--;

        if (cur == G){
            return move;
        }

        for (int i : {U,-D}){
            nxt = cur + i;

            if (0 < nxt && nxt <= F && !vis[nxt]){
                q.push(nxt);
                vis[nxt] = true;
            }
        }

        if (size == 0){
            size = q.size();
            move++;
        }
    }

    return -1;  // use the stairs
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int F,S,G,U,D;

    cin >> F >> S >> G >> U >> D;

    int move = elv_bfs(F,S,G,U,D);

    if (move == -1){
        cout << "use the stairs";
    }
    else {
        cout << move;
    }

    return 0;
}
