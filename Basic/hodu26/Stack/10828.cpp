#include <bits/stdc++.h>

using namespace std;

stack<int> st;

int main(){
  string order;
  int N, inpt;

  cin >> N;

  while (N--){
    cin >> order;

    if (order == "push"){
      cin >> inpt;
      st.push(inpt);
    }

    if (order == "pop"){
      if (st.empty()){
        cout << -1 << '\n';
      }
      else {
        cout << st.top() << '\n';
        st.pop();
      }
    }

    if (order == "size"){
      cout << st.size() << '\n';
    }

    if (order == "empty"){
      if (st.empty()){
        cout << 1 << '\n';
      }
      else {
        cout << 0 << '\n';
      }
    }

    if (order == "top"){
      if (st.empty()){
        cout << -1 << '\n';
      }
      else {
        cout << st.top() << '\n';
      }
    }
  }
}
