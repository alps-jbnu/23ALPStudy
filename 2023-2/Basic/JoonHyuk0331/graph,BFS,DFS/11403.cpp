#include <bits/stdc++.h>
using namespace std;
int adj[101][101];
int result[101][101];
int n;

void bfs() {
    for (int i = 1; i <= n; i++) {
        int vis[101]={0,};
        queue<int> q;

        q.push(i);
        //vis[i] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int nxt = 1; nxt <= n; nxt++) {
                if (adj[cur][nxt] == 1) {//cur에서 nxt로 가는 길이 있다면
                    if (vis[nxt]) continue;//이미 방문 했다면
                    q.push(nxt);
                    vis[nxt] = true;
                }
            }
        }
        for (int t = 1; t <= n; t++) {
            result[i][t] = vis[t];
        }
    }
}

int main() {
    cin >> n;//정점의 개수를 입력받는다
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            int input;
            cin >> input;
            adj[x][y] = input;
        }
    }

    //debug
    /*cout << "입력 전 result 배열 출력\n";
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            cout << result[x][y] << ' ';
        }
        cout << '\n';
    }*/
    /*cout << "입력받은 그래프 출력\n";
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            cout << adj[x][y] << ' ';
        }
        cout << '\n';
    }*/
    bfs();
    //cout << "입력 후 result 배열 출력\n";
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            cout << result[x][y] << ' ';
        }
        cout << '\n';
    }
}
