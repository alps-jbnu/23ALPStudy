#include <bits/stdc++.h>
using namespace std;

bool strfry(string a, string b){
  int x[26]={0, };
  int y[26]={0, };

  for(int i=0; i<a.length(); i++){
    x[a[i]-'a']++;
  }
  for(int i=0; i<b.length(); i++){
    y[b[i]-'a']++;
  }
  for(int i=0; i<26; i++){
    if(x[i]!=y[i]) return false;
  }
  return true;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  bool ans;
  int n;
  cin >> n;
  string a,b;
  for(int i=0; i<n; i++){
    cin>>a>>b;
    ans = strfry(a,b);
    if (ans == false) cout<< "Impossible" <<"\n";
    else cout << "Possible" <<"\n";
  }

}
