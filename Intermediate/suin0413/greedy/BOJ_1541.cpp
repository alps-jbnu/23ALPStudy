#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int tmp = 0; int ans = 0;
  int sign = 1;
  for(auto c : s){
    if(c == '+'){
        ans += tmp * sign;
        tmp = 0;

    }
    else if( c == '-'){
        ans += tmp * sign;
        tmp = 0;
        sign = -1;        
    }
    else{
        tmp *= 10;
        tmp += c - '0';
    }
  }
   ans += tmp * sign;
  cout << ans;
}
