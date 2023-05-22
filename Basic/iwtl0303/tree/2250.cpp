#include <bits/stdc++.h>
using namespace std;

const int MXN = 10010;
int lc[MXN], rc[MXN], N, colno, root;
pair<int, int> colLR[MXN];
void inorder(int curr, int d) {
  if (curr == -1) return;
  inorder(lc[curr], d + 1);
  colno++;
  auto &[lcol, rcol] = colLR[d];
  if (!lcol || colno < lcol) lcol = colno;
  if (!rcol || rcol < colno) rcol = colno;
  inorder(rc[curr], d + 1);
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  vector<bool> isRoot(N + 1, true);
  for (int i = 0; i < N; i++) {
    int p, l, r;
    cin >> p >> l >> r;
    lc[p] = l;
    rc[p] = r;

    if (l != -1) isRoot[l] = false;
    if (r != -1) isRoot[r] = false;
  }
  for (int i = 1; i <= N; i++)
    if (isRoot[i]) {
      root = i;
      break;
    }
  int mxWidth = 0, mxDepth = 0;
  inorder(root, 0);
  for (int d = 0; d < N; d++) {
    auto [lcol, rcol] = colLR[d];
    if (lcol + rcol == 0) break;
    int width = rcol - lcol + 1;
    if (mxWidth < width) {
      mxWidth = width;
      mxDepth = d;
    }
  }
  cout << mxDepth + 1 << ' ' << mxWidth;
}
