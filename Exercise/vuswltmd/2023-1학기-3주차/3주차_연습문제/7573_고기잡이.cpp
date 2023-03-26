#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

bool board[10'005][10'005];
int N, I, M;
vector<pair<int, int>> web;
vector<pair<int, int>> section_location;
int max_fish = 0;

void make_web() {
    int garo = I / 4;
    int sero = (I - (garo * 2)) / 2;

    while (1) {
        if (garo == 0) {
            break;
        }
        if (I == (garo * 2 + sero * 2)) {
            web.push_back({ garo, sero });
            garo--;
            sero++;
        }
        else {
            garo--;
            sero++;
        }
    }

    garo = (I / 4) + 1;
    sero = (I - (garo * 2)) / 2;


    while (1) {
        if (sero == 0) {
            break;
        }
        if (I == ((garo) * 2 + (sero) * 2)) {
            web.push_back({ garo, sero });
            garo++;
            sero--;
        }
    }
}

int main() {

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> I >> M;

    make_web();

    vector<int> vec1;
    vector<int> vec2;

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;

        board[x][y] = true;
        vec1.push_back(x);
        vec2.push_back(y);
    }

    for (auto i : vec1) {
        for (auto j : vec2) {
            section_location.push_back({ i, j });
            //물고기가 존재하는 위치 & 물고기간의 교차점
            // 그물을 펼칠 위치
        }
    }

    for (auto l : section_location) {
        int x1 = l.first;
        int y1 = l.second;

        for (auto k : web) {
            int web_x = k.first;
            int web_y = k.second;
            int cur_fish = 0;
             
            // if (x1 + web_x > N || y1 + web_y > N) continue; 잘 생각하면 할 필요 없음.

            for (int i = x1; i <= x1 + web_x; i++) {
                for (int j = y1; j <= y1 + web_y; j++) {

                    if (board[i][j] == 1) {
                        cur_fish++;
                    }
                }
            }

            if (max_fish < cur_fish) {
                max_fish = cur_fish;
            }
        }
    }

    cout << max_fish;
}

