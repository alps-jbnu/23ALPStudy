#include <bits/stdc++.h>
using namespace std;
#define ll long long  // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<int> chain;
int result;

int main() {
#ifndef ONLINE_JUDGE
  freopen("C:/Users/vl619/Development/vsCode_C++/input.txt", "r", stdin);
  freopen("C:/Users/vl619/Development/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  while (n--) {
    int len;
    cin >> len;
    chain.push_back(len);
  }

  sort(chain.begin(), chain.end());

  // 이 문제의 핵심은 길이는 1 말고는 중요하지 않다.
  while (chain.size() != 1) {
    chain[chain.size() - 2] += chain[chain.size() - 1];  // 가장 긴 체인 2개를 합침
    chain.pop_back();

    result++;
    chain[0]--;
    if (chain[0] == 0) {
      for (int i = 0; i < chain.size() - 1; i++) {
        chain[i] = chain[i + 1];
      }
      chain.pop_back();
    }
  }

  cout << result;

  return 0;
}