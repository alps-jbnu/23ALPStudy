#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N, M, k;
pair<int, int> scents[22][22]; // {shark number, scent count}
pair<int, int> board[22][22]; // {shark number, current direction}
pair<int, int> tmp[4][22][22]; // {shark number, current direction}
int priorities[22*22][5][5]; // shark number, current direction, priority

int dx[5] = {NULL, -1, 1, 0, 0};
int dy[5] = {NULL, 0, 0, -1, 1};

void move_shark(pair<int, int> pos) {
    int shark_num{board[pos.first][pos.second].first};
    int cur_dir{board[pos.first][pos.second].second};

    bool flag{false};
    for(int i{1}; i<=4; i++) {
        if(flag) break;

        int nxt_dir{priorities[shark_num][cur_dir][i]};
        int nx{pos.first+dx[nxt_dir]};
        int ny{pos.second+dy[nxt_dir]};

        if(nx<=0 || nx>N || ny<=0 || ny>N) continue;
        if(scents[nx][ny].second <= 0) {
            for(int j{}; j<4; j++) {
                if(tmp[j][nx][ny].first == 0) {
                    tmp[j][nx][ny].first = shark_num;
                    tmp[j][nx][ny].second = nxt_dir;
                    flag = true;
                    break;
                }
            }
        }
    }
    for(int i{1}; i<=4; i++) {
        if(flag) break;
        
        int nxt_dir{priorities[shark_num][cur_dir][i]};
        int nx{pos.first+dx[nxt_dir]};
        int ny{pos.second+dy[nxt_dir]};

        if(nx<=0 || nx>N || ny<=0 || ny>N) continue;
        if(scents[nx][ny].first == shark_num) {
            for(int j{}; j<4; j++) {
                if(tmp[j][nx][ny].first == 0) {
                    tmp[j][nx][ny].first = shark_num;
                    tmp[j][nx][ny].second = nxt_dir;
                    flag = true;
                    break;
                }
            }
        }
    }
}

void tmp_to_board() {
    for(int i{1}; i<=N; i++) {
        for(int j{1}; j<=N; j++) {
            board[i][j].first = 0;
            board[i][j].second = 0;

            for(int k{}; k<4; k++) {
                auto& cur{tmp[k][i][j]};
                if(cur.first > 0) {
                    if(board[i][j].first == 0 || board[i][j].first > cur.first) {
                        board[i][j].first = cur.first;
                        board[i][j].second = cur.second;
                    }
                }
            }
        }
    }
    memset(tmp, 0, sizeof(tmp));
}

void count_scent() {
    for(int i{1}; i<=N; i++) {
        for(int j{1}; j<=N; j++) {
            if(board[i][j].first == 0) {
                scents[i][j].second--;
            }
            else {
                scents[i][j].first = board[i][j].first;
                scents[i][j].second = k;
            }
        }
    }
}

bool one_check() {
    for(int i{1}; i<=N; i++) {
        for(int j{1}; j<=N; j++) {
            if(board[i][j].first > 1) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M>>k;
    for(int i{1}; i<=N; i++) {
        for(int j{1}; j<=N; j++) {
            cin>>board[i][j].first;
        }
    }
    for(int i{1}; i<=M; i++) {
        int cur_dir;
        cin>>cur_dir;
        for(int j{1}; j<=N; j++) {
            for(int k{1}; k<=N; k++) {
                if(board[j][k].first == i) {
                    board[j][k].second = cur_dir;
                }
            }
        }
    }
    for(int i{1}; i<=M; i++) {
        for(int j{1}; j<=4; j++) {
            for(int k{1}; k<=4; k++) {
                cin>>priorities[i][j][k];
            }
        }
    }

    int cnt{};
    count_scent();
    while(!one_check()) {
        cnt++;
        for(int i{1}; i<=N; i++) {
            for(int j{1}; j<=N; j++) {
                if(board[i][j].first == 0) continue;
                move_shark({i, j});
            }
        }
        tmp_to_board();
        count_scent();

        if(cnt > 1000) {
            cnt = -1;
            break;
        }
    }
    cout<<cnt<<"\n";

    return 0;
}