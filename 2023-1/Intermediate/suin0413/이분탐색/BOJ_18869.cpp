#include <bits/stdc++.h>
using namespace std;

int n, m, cnt = 0;
int arr[102][10002];

bool compare(int a, int b){
    for(int i = 0;i<n;i++){
        if(arr[a][i] != arr[b][i]) return false;
    }
    return true;
}

void func(int num){
    vector<int> uni;
    for(int i = 0;i<n;i++) uni.push_back(arr[num][i]);
    sort(uni.begin(), uni.end());
    uni.erase(unique(uni.begin(), uni.end()), uni.end());
    for(int i = 0; i < n; i++){
        int p = lower_bound(uni.begin(), uni.end(), arr[num][i]) - uni.begin();
        arr[num][i] = p;
    }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> n;
  for(int i = 0;i<m;i++){
    for(int j = 0;j<n;j++) cin >> arr[i][j];
  }
  for(int i = 0;i<m;i++) func(i);
  for(int i = 0;i<m-1;i++){
    for(int j = i+1;j<m;j++){
        if(compare(i,j)) cnt++;
    }
  }
  cout << cnt;
}
