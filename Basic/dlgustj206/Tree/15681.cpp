#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10e5 + 1;
int N, R, Q, U, V, q, subTreeSize[MAX];
vector<int> adj[MAX];
vector<bool> vis(MAX);

int countSubtreeNode(int cur) {
  vis[cur] = true;
  for (auto nxt : adj[cur]) {
    if (vis[nxt]) continue;
    subTreeSize[cur] += countSubtreeNode(nxt);
  }
  subTreeSize[cur]++;
  return subTreeSize[cur];
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> R >> Q;
  for (int i = 0; i < N - 1; i++) {
    cin >> U >> V;
    adj[U].push_back(V);
    adj[V].push_back(U);
  }

  countSubtreeNode(R);
  
  while (Q--) {
    cin >> q;
    cout << subTreeSize[q] << '\n';
  }
}
