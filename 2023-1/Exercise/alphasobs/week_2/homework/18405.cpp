#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int s, x, y;
int map[201][201];
int moveY[] = { 0, 0, 1, -1 };
int moveX[] = { 1, -1, 0, 0 };

bool IsOut(int y, int x) {
    if (x < 1 || y < 1 || x > n || y > n)
        return true;
    return false;
}

int main()
{
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n >> k;
    vector<pair<int, pair<int, int>>> virus;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
            if (map[i][j] != 0)
                virus.push_back({ map[i][j], {i, j} });
        }
    }
    cin >> s >> y >> x;

    // solution
    sort(virus.begin(), virus.end());
    int curTime = 0;
    while (curTime < s) {
        int virusCount = virus.size();
        for (int i = 0; i < virusCount; i++) {
            int curVirus = virus[i].first;
            int curY = virus[i].second.first;
            int curX = virus[i].second.second;

            for (int i = 0; i < 4; i++) {
                int nextY = curY + moveY[i];
                int nextX = curX + moveX[i];

                if (IsOut(nextY, nextX)) continue;
                if (map[nextY][nextX])   continue;

                map[nextY][nextX] = curVirus;
                virus.push_back({ curVirus, {nextY, nextX} });
            }
        }
        if (map[y][x])   break;
        curTime++;
    }

    // print
    cout << map[y][x] << '\n';
}