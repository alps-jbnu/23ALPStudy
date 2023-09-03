#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> tree[200005];
bool visited[200005];
int tree_len, start_branch, end_branch, branch_len;

void cal_tree(int node, int len) {
    visited[node] = true;
    tree_len = len;
    start_branch = node;

    if (tree[node].size() > 2)
        return;

    for (auto nxt : tree[node]) {
        if (!visited[nxt.first]) {
            visited[nxt.first] = true;
            cal_tree(nxt.first, nxt.second + len);
        }
    }
}

void cal_branch(int node, int len) {
    visited[node] = true;

    if (len > branch_len) {
        end_branch = node;
        branch_len = len;
    }

    for (auto nxt : tree[node]) {
        if (!visited[nxt.first]) {
            visited[nxt.first] = true;
            cal_branch(nxt.first, nxt.second + len);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, root;
    cin >> n >> root;


    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        tree[a].push_back({ b,c });
        tree[b].push_back({ a,c });
    }

    if (tree[root].size() >= 2) {
        cal_tree(root, 0);
        tree_len = 0;
        memset(visited, 0, sizeof(visited));
        cal_branch(root, 0);
    }

    else {
        cal_tree(root, 0);
        cal_branch(start_branch, 0);
    }

    cout << tree_len << " " << branch_len;
}