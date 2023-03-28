#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  deque<int> DQ;
  int n,num;
  string op;
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>op;
    if(op=="push_front"){
      cin>>num;
      DQ.push_front(num);
    }
    else if(op=="push_back"){
      cin>>num;
      DQ.push_back(num);
    }
    else if(op=="pop_front"){
      if (DQ.empty()) cout << -1 <<"\n";
      else{
        num=DQ.front();
        cout << num << "\n";
        DQ.pop_front();
      }
    }
    else if(op=="pop_back"){
      if (DQ.empty()) cout << -1 <<"\n";
      else{
        num=DQ.back();
        cout << num << "\n";
        DQ.pop_back();
      }
    }
    else if (op == "size") cout << DQ.size() << "\n";
    else if (op == "empty") {
      if (DQ.empty()) cout << -1 <<"\n";
      else cout << 0<<"\n";
    }
    else if (op == "front") {
      if (DQ.empty()) cout << -1 <<"\n";
      else cout << DQ.front()<<"\n";
    }
    else {
      if (DQ.empty()) cout << -1 <<"\n";
      else cout << DQ.back()<<"\n";
    }
  }
}