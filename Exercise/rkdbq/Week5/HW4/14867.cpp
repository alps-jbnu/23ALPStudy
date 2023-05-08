#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int a_capacity, b_capacity, a_goal, b_goal;
queue<pair<int, int>> Q;
map<pair<int, int>, long long> visited;

pair<int, int> fill(char x, pair<int, int> cur) {
    x == 'A' ?  cur.first = a_capacity : cur.second = b_capacity;
    return cur;
}
pair<int, int> empty(char x, pair<int, int> cur) {
    x == 'A' ? cur.first = 0 : cur.second = 0;
    return cur;
}
pair<int, int> move(char from, pair<int, int> cur) {
    pair<int, int> nxt{cur};
    if(from == 'A') {
        nxt.second = min(cur.second + cur.first, b_capacity);
        nxt.first = max(cur.second + cur.first - b_capacity, 0);
    }
    else {
        nxt.first = min(cur.first + cur.second, a_capacity);
        nxt.second = max(cur.first + cur.second - a_capacity, 0);
    }
    return nxt;
}

void bfs() {
    Q.push({0, 0});
    visited[{0, 0}] = 0;

    while(!Q.empty()) {
        auto cur{Q.front()};
        Q.pop();
        
        vector<pair<int, int>> nxt;
        nxt.push_back(fill('A', cur));
        nxt.push_back(fill('B', cur));
        nxt.push_back(empty('A', cur));
        nxt.push_back(empty('B', cur));
        nxt.push_back(move('A', cur));
        nxt.push_back(move('B', cur));

        for(int i{}; i<nxt.size(); i++) {
            if(visited.find(nxt[i]) == visited.end()) {
                Q.push(nxt[i]);
                visited[nxt[i]] = visited[cur] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>a_capacity>>b_capacity>>a_goal>>b_goal;
    bfs();
    long long ans{};
    if(visited.find({a_goal, b_goal}) == visited.end()) ans = -1;
    else ans = visited[{a_goal, b_goal}];
    cout<<ans;

    return 0;
}