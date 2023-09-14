#include <iostream>
#include <vector>
using namespace std;

int N, K;
int point[151];
bool vis[151];

int solve(int cur) {
    int cnt = 1;
    while(true) {
        int nxt = point[cur];
        if(nxt == K) return cnt;
        if(vis[nxt]) return -1;

        vis[nxt] = true;
        cur = nxt;
        cnt++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>K;
    for(int i{}; i<N; i++) {
        cin>>point[i];
    }
    vis[0] = true;
    cout<<solve(0);

    return 0;
}