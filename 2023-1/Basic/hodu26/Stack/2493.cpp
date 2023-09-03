#include <bits/stdc++.h>

using namespace std;

stack<int> top;
stack<pair<int,int>> findSig;
 
int main(){
  ios::sync_with_stdio(0);cin.tie(0);

  int N,topHight;

  cin >> N;

  int receiveSig[N] = {};

  for (int i=0;i<N;i++){
    cin >> topHight;
    top.push(topHight);
  }

  int n = N;
  while (!top.empty()){
    topHight = top.top();
    top.pop();

    while (!findSig.empty() && findSig.top().first <= topHight){
      receiveSig[findSig.top().second] = n;
      findSig.pop();
    }

    findSig.push(make_pair(topHight,n-1));
    n--;
  }

  for (int i=0;i<N;i++){
    cout << receiveSig[i] << ' ';
  }

  return 0;
}
