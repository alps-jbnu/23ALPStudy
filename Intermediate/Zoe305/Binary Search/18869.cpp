#include <bits/stdc++.h>

using namespace std;

int m, n;
int arr[102][10002];

void compress(int a[]){
  vector<int> vec(a, a + n);
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  for (int i = 0; i < n; i++)
    a[i] = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin();
}

bool compare(int a[], int b[]){
  for (int k = 0; k < n; k++)
    if (a[k] != b[k]) return false;
  return true;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n;
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++) cin >> arr[i][j];
    compress(arr[i]);
  }

  int ans = 0;
  for (int i = 0; i < m - 1; i++)
    for (int j = i + 1; j < m; j++)
      ans += compare(arr[i], arr[j]);

  cout << ans;
}