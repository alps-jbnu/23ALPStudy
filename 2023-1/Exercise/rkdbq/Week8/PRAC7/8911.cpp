#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int tc;
pair<int, int> pos;
int dir;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int most_left, most_right, most_top, most_bottom;

void init() {
    pos = {500, 500};
    dir = 0;
    most_left = most_right = most_top = most_bottom = 500;
}

void update() {
    most_left = min(most_left, pos.second);
    most_right = max(most_right, pos.second);
    most_top = min(most_top, pos.first);
    most_bottom = max(most_bottom, pos.first);
}

int area() {
    return (most_right-most_left)*(most_bottom-most_top);
}

// F: 한 눈금 앞으로
void F() {
    pos.first += dx[dir];
    pos.second += dy[dir];
    update();
}

// B: 한 눈금 뒤로
void B() {
    pos.first -= dx[dir];
    pos.second -= dy[dir];
    update();
}

// L: 왼쪽으로 90도 회전
void L() {
    dir = (dir+3)%4;
}

// R: 오른쪽으로 90도 회전
void R() {
    dir = (dir+1)%4;
}

string cmds;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>tc;
    for(int t{}; t<tc; t++) {
        init();
        cin>>cmds;
        for(int i{}; i<cmds.length(); i++) {
            auto cmd{cmds[i]};
            if(cmd=='F') F();
            else if(cmd=='B') B();
            else if(cmd=='L') L();
            else if(cmd=='R') R();
        }
        cout<<area()<<"\n";
    }
    return 0;
}