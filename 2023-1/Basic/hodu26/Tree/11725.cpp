#include <bits/stdc++.h>

using namespace std;

vector<int> tree[100003];
int parent[100003];

void tree_dfs(int cur){

    for (int nxt : tree[cur]){
        if (parent[cur] == nxt) continue;

        parent[nxt] = cur;

        tree_dfs(nxt);
    }
}   

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N,a,b;

    cin >> N;

    for (int i=0;i<N;i++){
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    tree_dfs(1);

    for (int i=2;i<=N;i++){
        cout << parent[i] << '\n';
    }

    return 0;
}
