#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string str;
  cin>>str;
  list<char> L;
  for(auto c:str) L.push_back(c);
  auto cus=L.end();
  int m;
  cin>>m;

  while(m--){
    char op;
    cin>>op;
    
    if(op=='P'){
      char add;
      cin>>add;
      L.insert(cus, add);
    }
    else if(op=='B'){
      if(cus!=L.begin()){
        cus--;
        cus=L.erase(cus);
      }
    }
    else if(op=='L'){
      if(cus!=L.begin()){
        cus--;
      }
    }
    else{
      if(cus!=L.end()){
        cus++;
      }
    }
  }
  for(auto c:L) cout<<c;
}