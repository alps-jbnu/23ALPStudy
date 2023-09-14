#include <bits/stdc++.h>

using namespace std;

int dx[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

int answer(int x, int y, int eat_fish, vector<vector<pair<int, int>>> fish, vector<pair<int, int>> fish_num) {
    auto cur_fish = fish[x][y];
    int cur_num = cur_fish.first;
    int cur_dir = cur_fish.second;
    fish_num[cur_num] = make_pair(-1, -1);
    fish[x][y] = make_pair(0, 0);
    for (int i = 1; i <= 16; i++) {
        auto move_fish = fish_num[i];
        int origin_x = move_fish.first;
        int origin_y = move_fish.second;
        if (origin_x == -1 || origin_y == -1) continue;
        int origin_num = fish[origin_x][origin_y].first;
        int move_dir = fish[origin_x][origin_y].second;
        for (int j = 0; j < 8; j++) {
            int move_dir_change = (move_dir + j);
            if (move_dir_change > 8) move_dir_change -= 8;
            int move_x = move_fish.first + dx[move_dir_change];
            int move_y = move_fish.second + dy[move_dir_change];
            if (move_x < 0 || move_x >= 4 || move_y < 0 || move_y >= 4) continue;
            if (move_x == x && move_y == y) continue;
            int change_num = fish[move_x][move_y].first;
            int change_dir = fish[move_x][move_y].second;
            fish[move_x][move_y] = make_pair(origin_num, move_dir_change);
            fish[origin_x][origin_y] = make_pair(change_num, change_dir);
            fish_num[origin_num] = make_pair(move_x, move_y);
            fish_num[change_num] = make_pair(origin_x, origin_y);
            break;
        }
    }
    int shark_x = x + dx[cur_dir];
    int shark_y = y + dy[cur_dir];
    int max_fish = eat_fish + cur_num;
    if (shark_x < 0 || shark_x >= 4 || shark_y < 0 || shark_y >= 4) {
        return max_fish;
    }
    while (shark_x >= 0 && shark_x < 4 && shark_y >= 0 && shark_y < 4) {
        if (fish[shark_x][shark_y].first == 0) {
            shark_x += dx[cur_dir]; shark_y += dy[cur_dir];
            continue;
        }
        max_fish = max(max_fish, answer(shark_x, shark_y, eat_fish + cur_num, fish, fish_num));
        shark_x += dx[cur_dir]; shark_y += dy[cur_dir];
    }
    return max_fish;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<pair<int, int>>> fish;
    vector<pair<int, int>> fish_num;
    fish_num.emplace_back(-1, -1);
    pair<int, int> fish_num_temp[17];
    for (int i = 0; i < 4; i++) {
        fish.emplace_back(vector<pair<int, int>>());
        for (int j = 0; j < 4; j++) {
            int a, b; cin >> a >> b;
            fish[i].emplace_back(a, b);
            fish_num_temp[a] = make_pair(i, j);
        }
    }
    for (int i = 1; i <= 16; i++) {
        fish_num.push_back(fish_num_temp[i]);
    }
    cout << answer(0, 0, 0, fish, fish_num);
    return 0;
}
