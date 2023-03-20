#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Position {
    public:
    int x;
    int y;
    Position() {
        x = 0;
        y = 0;
    }
    Position(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

int dx[9] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

Position jongsoo;
vector<Position> arduinos;

int R, C;
string commands;

bool isGameOver() {
    for(int i{}; i<arduinos.size(); i++) {
        auto cur = arduinos[i];
        if(jongsoo.x == cur.x && jongsoo.y == cur.y) return true;
    }
    return false;
}

int distance(Position a, Position b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y - b.y)*(a.y - b.y);
}

Position moveArduino(int idx) {
    auto cur = arduinos[idx];
    auto dis = 100001;
    auto ret = Position(0, 0);
    for(int i{}; i<9; i++) {
        auto nxt = cur;
        nxt.x += dx[i];
        nxt.y += dy[i];
        if(i == 4) continue;
        if(nxt.x < 0 || nxt.x >= R) continue;
        if(nxt.y < 0 || nxt.y >= C) continue;
        if(dis > distance(jongsoo, nxt)) {
            dis = distance(jongsoo, nxt);
            ret = nxt;
        }
    }
    return ret;
}
void destroyArduino() {
    queue<Position> Q;
    int cnt[101][101];
    for(int i{}; i<101; i++) for(int j{}; j<101; j++) cnt[i][j] = 0;
    for(int i{}; i<arduinos.size(); i++) {
        auto cur = arduinos[i];
        cnt[cur.x][cur.y]++;
        Q.push(cur);
    }

    arduinos.clear();
    while(!Q.empty()) {
        auto cur = Q.front();
        if(cnt[cur.x][cur.y]==1) arduinos.push_back(cur);
        Q.pop();
    }
}

char board[101][101];

void printBoard() {
    for(int i{}; i<101; i++) for(int j{}; j<101; j++) board[i][j] = '.';
    board[jongsoo.x][jongsoo.y] = 'I';
    for(int i{}; i<arduinos.size(); i++) board[arduinos[i].x][arduinos[i].y] = 'R';
    // cout<<"\n";
    for(int i{}; i<R; i++) {
        for(int j{}; j<C; j++) {
            cout<<board[i][j];
        }
        cout<<"\n";
    }
    // cout<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>R>>C;
    for(int i{}; i<R; i++) {
        for(int j{}; j<C; j++) {
            cin>>board[i][j];
            if(board[i][j] == 'I') jongsoo = Position(i, j);
            else if(board[i][j] == 'R') arduinos.push_back(Position(i, j));
        }
    }

    bool gameOver = false;
    cin>>commands;
    for(int i{}; i<commands.size(); i++) {
        // 1. 먼저, 종수가 아두이노를 8가지 방향(수직,수평,대각선)으로 이동시키거나, 그 위치에 그대로 놔둔다.
        int curCommand = commands[i] - '0' - 1;
        jongsoo.x += dx[curCommand];
        jongsoo.y += dy[curCommand];

        // 2. 종수의 아두이노가 미친 아두이노가 있는 칸으로 이동한 경우에는 게임이 끝나게 되며, 종수는 게임을 지게 된다.
        if(gameOver = isGameOver()) { 
            cout<<"kraj "<<i+1<<"\n";
            break;
        }

        // 3. 미친 아두이노는 8가지 방향 중에서 종수의 아두이노와 가장 가까워 지는 방향으로 한 칸 이동한다. 즉, 종수의 위치를 (r1,s1), 미친 아두이노의 위치를 (r2, s2)라고 했을 때, |r1-r2| + |s1-s2|가 가장 작아지는 방향으로 이동한다.
        for(int j{}; j<arduinos.size(); j++) {
            arduinos[j] = moveArduino(j);
        }

        // 4. 미친 아두이노가 종수의 아두이노가 있는 칸으로 이동한 경우에는 게임이 끝나게 되고, 종수는 게임을 지게 된다.
        if(gameOver = isGameOver()) { 
            cout<<"kraj "<<i+1<<"\n";
            break;
        }

        // 5. 2개 또는 그 이상의 미친 아두이노가 같은 칸에 있는 경우에는 큰 폭발이 일어나고, 그 칸에 있는 아두이노는 모두 파괴된다.
        destroyArduino();

        // cout<<i<<": \n";
        // printBoard();
    }

    if(!gameOver) printBoard();

    return 0;
}