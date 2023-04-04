#include <iostream>
using namespace std;

int N, L;
int map[101][101];

int ans; 

void row_check(int x, int y, int cnt, bool is_possible) {
    if(y == N-1) {
        if(is_possible) ans++;
        return;
    }
    int cur = map[x][y];
    int nxt = map[x][y+1];
    if(nxt==cur) row_check(x, y+1, cnt+1, is_possible);
    else if(nxt==cur+1) {
        if(cnt>=L) row_check(x, y+1, 1, is_possible);
        else return;
    }
    else if(nxt==cur-1) {
        int len = 0;
        int ny = 0;
        for(int i{y+1}; i<N; i++) {
            if(map[x][i]==nxt) len++;
            else return;
            if(len>=L) {
                ny = i;
                break;
            }
        }
        if(len>=L) row_check(x, ny, 0, is_possible);
    }
    else return;
}

void col_check(int x, int y, int cnt, bool is_possible) {
    if(x == N-1) {
        if(is_possible) ans++;
        return;
    }
    int cur = map[x][y];
    int nxt = map[x+1][y];
    if(nxt==cur) col_check(x+1, y, cnt+1, is_possible);
    else if(nxt==cur+1) {
        if(cnt>=L) col_check(x+1, y, 1, is_possible);
        else return;
    }
    else if(nxt==cur-1) {
        int len = 0;
        int nx = 0;
        for(int i{x+1}; i<N; i++) {
            if(map[i][y]==nxt) len++;
            else return;
            if(len>=L) {
                nx = i;
                break;
            }
        }
        if(len>=L) col_check(nx, y, 0, is_possible);
    }
    else return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>L;
    for(int i{}; i<N; i++) {
        for(int j{}; j<N; j++) {
            cin>>map[i][j];
        }
    }
    for(int i{}; i<N; i++) {
        row_check(i, 0, 1, true);
        col_check(0, i, 1, true);
    }
    cout<<ans;
    

    return 0;
}