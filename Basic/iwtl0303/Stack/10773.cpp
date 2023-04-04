#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  stack<int> s;
  int k,num,ans=0;
  cin >> k;
  for (int i = 0; i < k; i++){
    cin >> num;
    if (num == 0) s.pop();
    else s.push(num);
  }
  while(!(s.empty())){
    ans+=s.top();
    s.pop();
  }
  cout<<ans;
}