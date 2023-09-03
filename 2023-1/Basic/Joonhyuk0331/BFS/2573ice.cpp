#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<pair<int, int>> input;
int n, m;
int arr[1000][1000];
bool check[1000][1000];//크기 재정의?

int cnt;
int mCnt = 0;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };//4방향

bool fin() {
    for (int i = 0; i < input.size(); i++) 
    {
        int row = input[i].first;
        int col = input[i].second;
        if (arr[row][col]) 
            return false;
    }
    return true;
}

bool div() {
    int inputCnt = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < input.size(); i++) {
        int row = input[i].first;
        int col = input[i].second;
        if (!arr[row][col]) 
            continue;
        else {
            q.push({ row, col });
            break;
        }
    }
    while (!q.empty()) {//bfs
        int row = q.front().first;
        int col = q.front().second;
        inputCnt++;
        q.pop();
        check[row][col] = true;
        for (int j = 0; j < 4; j++) {
            int nRow = row + dy[j];
            int nCol = col + dx[j];
            if (check[nRow][nCol] || nRow < 0 || nRow >= n || nCol < 0 || nCol >= m)
                continue;
            if (arr[nRow][nCol]) {
                check[nRow][nCol] = true;
                q.push({ nRow, nCol });
            }
        }
    }
    memset(check, 0, sizeof(check));
    if (inputCnt == input.size() - mCnt) return false;
    return true;
}

void do_solution() {
    for (int i = 0; i < input.size(); i++) {
        int row = input[i].first;
        int col = input[i].second;

        if (!arr[row][col]) continue;

        check[row][col] = true;
        int oceanCnt = 0;
        for (int j = 0; j < 4; j++) {
            int nRow = row + dy[j];
            int nCol = col + dx[j];

            if (check[nRow][nCol] || nRow < 0 || nRow >= n || nCol < 0 || nCol >= m)
                continue;
            if (!arr[nRow][nCol])
                oceanCnt++;
        }
        if (arr[row][col] - oceanCnt <= 0) {
            mCnt++;
            arr[row][col] = 0;
        }
        else arr[row][col] -= oceanCnt;
    }
    memset(check, 0, sizeof(check));
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j]) input.push_back({ i, j });
        }
    }

    while (1)
    {
        do_solution();
        cnt++;
        if (div()) {
            cout << cnt << '\n';
            return 0;
        }
        if (fin()) {
            cout << 0 << '\n';
            return 0;
        }
    }
    return 0;
}
