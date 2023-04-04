#include <iostream>
#include <algorithm>
using namespace std;

class Fish {
    public:
    int x;
    int y;
    int d;
    bool isLive;
    Fish(int x, int y, int d) {
        this->x = x;
        this->y = y;
        this->d = d;
        isLive = true;
    }
    Fish(int x, int y, int d, bool isLive) {
        this->x = x;
        this->y = y;
        this->d = d;
        this->isLive = isLive;
    }
    Fish() {
        x = y = d = -1;
        isLive = false;
    }
};

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int ans;

void printMap(int map[][4]) {
    for(int i{}; i<4; i++) {
        for(int j{}; j<4; j++) {
            cout<<map[i][j] + 1<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void step(Fish bef[], Fish shark, int befScore) {
    Fish cur[16];
    int fishMap[4][4];
    for(int i{}; i<4; i++) for(int j{}; j<4; j++) fishMap[i][j] = -1;
    for(int i{}; i<16; i++) {
        cur[i].x = bef[i].x;
        cur[i].y = bef[i].y;
        cur[i].d = bef[i].d;
        cur[i].isLive = bef[i].isLive;

        fishMap[cur[i].x][cur[i].y] = i;
    }

    // 물고기들이 이동함
    for(int i{}; i<16; i++) {
        if(!cur[i].isLive) continue;
        for(int j{}; j<=8; j++) {
            int nxtD = (cur[i].d + j) % 8;
            int nX = cur[i].x + dx[nxtD];
            int nY = cur[i].y + dy[nxtD];

            if(nX < 0 || nX >= 4) continue;
            if(nY < 0 || nY >= 4) continue;
            if(nX == shark.x && nY == shark.y) continue;

            cur[i].d = nxtD;

            int tempIdx = fishMap[nX][nY];
            Fish temp = Fish(cur[tempIdx].x, cur[tempIdx].y, cur[tempIdx].d, cur[tempIdx].isLive);

            cur[tempIdx].x = cur[i].x;
            cur[tempIdx].y = cur[i].y;

            cur[i].x = temp.x;
            cur[i].y = temp.y;

            fishMap[cur[i].x][cur[i].y] = i;
            fishMap[cur[tempIdx].x][cur[tempIdx].y] = tempIdx;
            
            break;
        }
    }

    // 상어가 이동함
    for(int i{1}; i<=3; i++) {
        int nSharkX = shark.x + dx[shark.d] * i;
        int nSharkY = shark.y + dy[shark.d] * i;

        if(nSharkX < 0 || nSharkX >= 4) {
            ans = max(ans, befScore);
            return;
        }
        if(nSharkY < 0 || nSharkY >= 4) {
            ans = max(ans, befScore);
            return;
        }
        if(!cur[fishMap[nSharkX][nSharkY]].isLive) {
            ans = max(ans, befScore);
            continue;
        }
        // 상어가 현재 칸의 물고기를 잡아 먹음
        int preyIdx = fishMap[nSharkX][nSharkY];
        cur[preyIdx].isLive = false;
        step(cur, Fish(nSharkX, nSharkY, cur[preyIdx].d), befScore + preyIdx + 1);
        cur[preyIdx].isLive = true;
    }
}

Fish fishes[16];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Fish st;
    int st_a;
    for(int i{}; i<4; i++) {
        for(int j{}; j<4; j++) {
            int a, b;
            cin>>a>>b;
            fishes[a-1] = Fish(i, j, b-1);
            if(i==0 && j==0) {
                st = Fish(i, j, b-1);
                st_a = a;
            }
        }
    }

    fishes[st_a - 1].isLive = false;
    step(fishes, Fish(0, 0, st.d), st_a);
    cout<<ans;

    return 0;
}