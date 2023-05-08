#include <iostream>
using namespace std;

int arr[3000][3000];
int ans[5] = { };

void func(int a, int b, int n){ // 위치: arr[a][b] ~ arr[a+n-1][b+n-1]
    int pap = arr[a][b];
    bool val = 1;
    if(n==1) { // base condition
        ans[pap+1]++;
        return;
    }

    for(int i = a;i<a+n;i++){
        for(int j = b;j<b+n;j++){
            if(arr[i][j] != pap) {
                val = 0;
                break;
            }
        }
    }
    if(val == 1){
        ans[pap+1]++;
        return;
    }
    else {
        int sec = n/3;
        func(a, b, sec);
        func(a, b+sec, sec);
        func(a, b+sec*2, sec);
        func(a+sec, b, sec);
        func(a+sec, b+sec, sec);
        func(a+sec, b+sec*2, sec);
        func(a+sec*2, b, sec);
        func(a+sec*2, b+sec, sec);
        func(a+sec*2, b+sec*2, sec);
        return;
    }
  }


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
        cin >> arr[i][j];
    }
  }
  func(0, 0, n);
  cout << ans[0] << "\n" << ans[1] << "\n" << ans[2];
}
