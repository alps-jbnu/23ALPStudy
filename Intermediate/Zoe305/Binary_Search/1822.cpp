#include <bits/stdc++.h>

using namespace std;

vector<int> A, B;
int n, m;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  int num;
  for (int i = 0; i < n; i++){
    cin >> num;
    A.push_back(num);
  }
  sort(A.begin(), A.end());

  for (int i = 0; i < m; i++){
    cin >> num;
    B.push_back(num);
  }
  sort(B.begin(), B.end());

  vector<int> ans;
  for (int num : A){
    if (binary_search(B.begin(), B.end(), num)) continue;
    ans.push_back(num);
  }

  cout << ans.size() << "\n";
  for (int num : ans) cout << num << ' ';
}