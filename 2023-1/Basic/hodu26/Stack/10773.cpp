#include <bits/stdc++.h>

using namespace std;

stack<int> st;

int main(){
  ios::sync_with_stdio(0);cin.tie(0);

  int K, inpt, sum=0;

  cin >> K;

  while (K--){
    cin >> inpt;

    if (inpt == 0){
      st.pop();
    }
    else {
      st.push(inpt);
    }
  }

  int len = st.size();
  for (int i=0;i<len;i++){
    sum += st.top();
    st.pop();
  }

  cout << sum;

  return 0;
}
