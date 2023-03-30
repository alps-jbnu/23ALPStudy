#include <bits/stdc++.h>
using namespace std;

void strfry(string a, string b){
  int x[26]={0, };
  int y[26]={0, };
  int cnt=0;
  for(int i=0; i<a.length(); i++){
    x[a[i]-'a']++;
  }
  for(int i=0; i<b.length(); i++){
    y[b[i]-'a']++;
  }
  for(int i=0; i<26; i++){
    if(x[i]!=y[i]) cnt+=abs(x[i]-y[i]);
  }
  cout << cnt;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  string a,b;
  cin >> a >> b;
  strfry(a,b);

}
