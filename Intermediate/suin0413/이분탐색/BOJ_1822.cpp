#include <bits/stdc++.h>
using namespace std;

int n, m, a[500005], b[500005];
vector<int> v;

int main(void) 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0;i<n;i++) cin >> a[i];
  for(int i = 0;i<m;i++) cin >> b[i];
  sort(a,a+n);
  sort(b,b+m);
  for(int i = 0;i<n;i++){
    if(!binary_search(b,b+m,a[i])) v.push_back(a[i]);
  }
  cout << v.size() << "\n";
  if(v.size()>0){
    for(int i = 0;i<v.size();i++) cout << v[i] << " ";
  }
}
