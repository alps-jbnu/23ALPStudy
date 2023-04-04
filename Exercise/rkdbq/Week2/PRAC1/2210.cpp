#include <iostream>
#include <set>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

char board[5][5];
set<string> S;

void dfs(int x, int y, int level, string cur) {
    if(level == 6) {
        S.insert(cur);
        return;
    }
    for(int i{}; i<4; i++) {
        int nxtX = x+dx[i];
        int nxtY = y+dy[i];
        if(nxtX<0 || nxtX>=5) continue;
        if(nxtY<0 || nxtY>=5) continue;
        string nxtStr = cur;
        nxtStr.append(to_string(board[nxtX][nxtY]));
        dfs(nxtX, nxtY, level+1, nxtStr);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i{}; i<5; i++) {
        for(int j{}; j<5; j++) {
            cin>>board[i][j];
        }
    }
    for(int i{}; i<5; i++) {
        for(int j{}; j<5; j++) {
            dfs(i, j, 0, "");
        }
    }
    cout<<S.size();

    return 0;
}