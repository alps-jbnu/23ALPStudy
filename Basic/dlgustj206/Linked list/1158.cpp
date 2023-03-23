#include <iostream>
#include <vector>
using namespace std;

int pre[5001];
int nxt[5001];
vector<int> v;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k, len = 0;
  cin >> n >> k;
  for(int i = 1; i <= n; ++i){
    pre[i] = (i == 1) ? n : i - 1;
    nxt[i] = (i == n) ? 1 : i + 1;
    ++len;
  }
  int i = 1;
  for(int cur = 1; len != 0; cur = nxt[cur]){
    if(i == k){
      pre[nxt[cur]] = pre[cur];
      nxt[pre[cur]] = nxt[cur];
      v.push_back(cur);
      i = 1;
      --len;
    } else ++i;
  }
  cout << "<";
  for(size_t i = 0; i < v.size(); ++i) {
    cout << v[i];
    if(i != v.size() - 1) cout << ", ";
  }
  cout << ">";
}