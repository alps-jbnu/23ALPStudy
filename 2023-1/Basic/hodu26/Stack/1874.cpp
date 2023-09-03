#include <bits/stdc++.h>

using namespace std;

stack<int> in;
queue<char> ans;

int checkTop(int arr[], int itr){
  if (!in.empty() && arr[itr] == in.top()){
    in.pop();
    itr++;

    ans.push('-');

    itr = checkTop(arr, itr);
  }

  return itr;
}

int main(){
  ios::sync_with_stdio(0);cin.tie(0);

  int n, itr=0;

  cin >> n;

  int arr[n];

  for (int i=0;i<n;i++){
    cin >> arr[i];

    in.push(i+1);

    ans.push('+');

    itr = checkTop(arr, itr);
  }

  if (itr == n){
    while (!ans.empty()){
      cout << ans.front() << '\n';
      ans.pop();
    }
  }
  else {
    cout << "NO\n";
  }

  return 0;
}
