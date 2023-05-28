#include <iostream>
#include<queue>
#include<vector>
using namespace std;

int inDegree[32001];
vector<int> graph[32001];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        inDegree[b]++;
        graph[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {

        if (inDegree[i] == 0) {
            pq.push(i);
        }

    }
    while (!pq.empty()) {

        int cur = pq.top();
        pq.pop();
        cout << cur << ' ';

        for (int i = 0; i < graph[cur].size(); i++) {

            int next = graph[cur][i];

            if (--inDegree[next] == 0) {
                pq.push(next);
            }
        }

    }
    return 0;
}
