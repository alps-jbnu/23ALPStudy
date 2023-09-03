#include <bits/stdc++.h>

using namespace std;

int a[500005];
int N;

int lower_idx(int target, int len){
  int st = 0;
  int en = len;
  while(st < en){
    int mid = (st+en)/2;
    if(a[mid] >= target) en = mid;
    else st = mid+1;
  }
  return st;
}

int upper_idx(int target, int len){
  int st = 0;
  int en = len;
  while(st < en){
    int mid = (st+en)/2;
    if(a[mid] > target) en = mid;
    else st = mid+1;
  }
  return st;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++) cin >> a[i];
  sort(a,a+N);
  
  int M;
  cin >> M;
  while(M--){
    int t;
    cin >> t;
    cout << upper_idx(t,N)-lower_idx(t,N) << '\n';
  }
}