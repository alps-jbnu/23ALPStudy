#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
int parent[100001];
long long cnt[100001];
vector<pair<int, int>> line;
bool line_break[100001];
stack<int> line_break_stack;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    else if (a < b) {
        parent[b] = a;
        cnt[a] += cnt[b];
        cnt[b] = 0;
    } else if (a > b) {
        parent[a] = b;
        cnt[b] += cnt[a];
        cnt[a] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        cnt[i] = 1;
    }
    line.emplace_back(-1, -1);
    for (int i = 0; i < M; i++) {
        int X, Y; cin >> X >> Y;
        line.emplace_back(X, Y);
    }
    for (int i = 0; i < Q; i++) {
        int num; cin >> num;
        line_break[num] = true;
        line_break_stack.emplace(num);
    }
    for (int i = 1; i < line.size(); i++) {
        if (line_break[i]) continue;
        auto cur_line = line[i];
        merge(cur_line.first, cur_line.second);
    }
    long long answer = 0;
    while (!line_break_stack.empty()) {
        int num = line_break_stack.top(); line_break_stack.pop();
        auto cur_line = line[num];
        int parent_x = find(cur_line.first), parent_y = find(cur_line.second);
        if (parent_x != parent_y) {
            answer += cnt[parent_x] * cnt[parent_y];
            merge(cur_line.first, cur_line.second);
        }
    }
    cout << answer;
    return 0;
}
