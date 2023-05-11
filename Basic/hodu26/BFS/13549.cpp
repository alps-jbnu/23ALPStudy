#include <bits/stdc++.h>

using namespace std;

bool vis[100003];

int find_bfs(int N, int M){
    queue<int> q;  // <X,time>

    int X,x;  // x == 2*X set
    int minT = 0;

    q.push(N);
    vis[N] = true;

    x = N;
    while (0 < 2*x && 2*x <= 100000 && !vis[2*x]){   // 2*X 
        x = 2*x;
        q.push(x);
        vis[x] = true;
    }

    int size = q.size();

    while (!q.empty()){
        X = q.front(); q.pop();
        size--;

        if (X == M){
            return minT;
        }

        for (int nxt : {X-1, X+1}){
            if (0 <= nxt && nxt <= 100000 && !vis[nxt]){
                q.push(nxt);
                vis[nxt] = true;

                x = nxt;
                while (0 < 2*x && 2*x <= 100000 && !vis[2*x]){   // 2*X 
                    x = 2*x;
                    q.push(x);
                    vis[x] = true;
                }
            }
        }

        if (size == 0){
            size = q.size();
            minT++;
        }
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N,K;

    cin >> N >> K;

    cout << find_bfs(N,K);

    return 0;
}
