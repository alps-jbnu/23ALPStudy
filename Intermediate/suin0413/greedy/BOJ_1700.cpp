// 풀었다가 틀림 너무 슬픔.. 다시 고쳐봐야 됨 하하
#include <bits/stdc++.h>
using namespace std;

int n, k, ans = 0;
int a[102];
int on[102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for(int i = 0;i<k;i++) cin >> a[i];
  for(int i = 0;i<n;i++) on[i] = a[i];
  for(int i = n;i<k;i++){
    if((find(on, on+n, a[i])-on)<n) continue; // 이미 꽂힘
    else{ // 빼고 꽂기
        int max = 0; int idx = 0;
        for(int j = 0;j<n;j++){
            int cur = find(a+i, a+k, on[j]) - a;
            if(cur > max){
                max = cur;
                idx = j;
            }
        }
        on[idx] = a[i];
        ans++;
    }
  }
  cout << ans;
}
