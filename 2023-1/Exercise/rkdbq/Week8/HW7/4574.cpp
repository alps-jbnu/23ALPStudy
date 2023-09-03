#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

vector<pair<int, int>> unvisited;
pair<int, int> tiles[36];
bool used[36];
int board[9][9];

void print_board() {
    for(int i{}; i<9; i++) {
        for(int j{}; j<9; j++) {
            if(board[i][j]!=-1) cout<<board[i][j];
            else cout<<". ";
        }
        cout<<"\n";
    }
}

bool row_check(int row, int num) {
    for(int i{}; i<9; i++) {
        if(board[row][i] == num) return false;
    }
    return true;
}

bool col_check(int col, int num) {
    for(int i{}; i<9; i++) {
        if(board[i][col] == num) return false;
    }
    return true;
}

bool three_check(pair<int, int> left_top, int num) {
    for(int i{left_top.first}; i<left_top.first+3; i++) {
        for(int j{left_top.second}; j<left_top.second+3; j++) {
            if(board[i][j] == num) return false;
        }
    }
    return true;
}

pair<int, int> left_top(pair<int, int> cur) {
    pair<int, int> ret;

    if(cur.first<3) ret.first = 0;
    else if(cur.first<6) ret.first = 3;
    else ret.first = 6;

    if(cur.second<3) ret.second = 0;
    else if(cur.second<6) ret.second = 3;
    else ret.second = 6;

    return ret;
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool flag{false};

void dfs(int cur_idx) {
    if(cur_idx == unvisited.size()) {
        print_board();
        flag = true;
        return;
    }
    if(flag) return;

    auto cur = unvisited[cur_idx];
    if(board[cur.first][cur.second] != -1) {
        dfs(cur_idx+1);
        return;
    }

    for(int i{}; i<4; i++) {
        auto sec{cur};
        sec.first += dx[i];
        sec.second += dy[i];

        if(sec.first<0 || sec.first>=9) continue;
        if(sec.second<0 || sec.second>=9) continue;
        if(board[sec.first][sec.second] != -1) continue;

        for(int j{}; j<36; j++) {
            if(used[j]) continue;
            if(!row_check(cur.first, tiles[j].first) || !row_check(sec.first, tiles[j].second)) continue;
            if(!col_check(cur.second, tiles[j].first) || !col_check(sec.second, tiles[j].second)) continue;
            if(!three_check(left_top(cur), tiles[j].first) || !three_check(left_top(sec), tiles[j].second)) continue;
            used[j] = true;
            board[cur.first][cur.second] = tiles[j].first;
            board[sec.first][sec.second] = tiles[j].second;
            dfs(cur_idx+1);
            used[j] = false;
            board[cur.first][cur.second] = -1;
            board[sec.first][sec.second] = -1;
        }
        for(int j{}; j<36; j++) {
            if(used[j]) continue;
            if(!row_check(cur.first, tiles[j].second) || !row_check(sec.first, tiles[j].first)) continue;
            if(!col_check(cur.second, tiles[j].second) || !col_check(sec.second, tiles[j].first)) continue;
            if(!three_check(left_top(cur), tiles[j].second) || !three_check(left_top(sec), tiles[j].first)) continue;
            used[j] = true;
            board[cur.first][cur.second] = tiles[j].second;
            board[sec.first][sec.second] = tiles[j].first;
            dfs(cur_idx+1);
            used[j] = false;
            board[cur.first][cur.second] = -1;
            board[sec.first][sec.second] = -1;
        }
    }
}

int N, U, V;
string LU, LV, loc;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{};
    for(int i{1}; i<=9; i++) {
        for(int j{i+1}; j<=9; j++) {
            tiles[t++] = {i, j};
        }
    }

    int p{};
    while(true) {
        memset(board, -1, sizeof(board));
        memset(used, false, sizeof(used));
        unvisited.clear();
        flag = false;

        cin>>N;
        if(N==0) break;

        for(int i{}; i<N; i++) {
            cin>>U>>LU>>V>>LV;
            board[LU[0]-'A'][LU[1]-'1'] = U;
            board[LV[0]-'A'][LV[1]-'1'] = V;
            for(int j{}; j<36; j++) {
                if(tiles[j].first == U && tiles[j].second == V) used[j] = true;
                if(tiles[j].second == U && tiles[j].first == V) used[j] = true;
            }
        }

        for(int i{}; i<9; i++) {
            cin>>loc;
            board[loc[0]-'A'][loc[1]-'1'] = i+1;
        }

        for(int i{}; i<9; i++) {
            for(int j{}; j<9; j++) {
                if(board[i][j] == -1) {
                    unvisited.push_back({i, j});
                }
            }
        }

        cout<<"Puzzle "<<++p<<"\n";
        dfs(0);
    }
    
    return 0;
}