#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int N, M, Q;
int parent[100'005];
pair<int, int> graph[100'005];
int disconnect[100'005];
bool check[100'005];
long long ans;

int find(int a) {
    if (parent[a] < 0) return a;
    return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
    int A = find(a);
    int B = find(b);

    if (A != B) {
        parent[A] += parent[B];
        parent[B] = A;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> Q;
    fill(parent, parent + 100'005, -1);

    for (int i = 1; i <= M; i++) {
        cin >> graph[i].first >> graph[i].second;
        check[i] = true;
    }

    for (int i = 1; i <= Q; i++) {
        cin >> disconnect[i];
        check[disconnect[i]] = false;
    }

    for (int i = 1; i <= M; i++) {
        if (check[i] == true) Union(graph[i].first, graph[i].second);
    }

    for (int i = Q; i >= 1; i--) {
        int temp = disconnect[i];
        int a = find(graph[temp].first);
        int b = find(graph[temp].second);

        if (a != b) {
            ans += parent[a] * parent[b];
        }

        Union(a, b);
    }

    cout << ans;
}

