#include <iostream>
using namespace std;
char arr[100][100];

bool same(int a, int b, int c){
    for(int i = 0; i<c;i++){
        for(int j = 0;j<c;j++){
            if(arr[a+i][b+j] != arr[a][b])
            return false;
        }
    }
    return true;
}

void func(int a, int b, int n){
    if (n == 1){
        cout << arr[a][b];
        return;
    }
    if(same(a,b,n)) {
        cout << arr[a][b];
        return;
    }
    int h = n/2;
    cout<< "(";
    func(a,b,h);
    func(a,b+h,h);
    func(a+h,b,h);
    func(a+h,b+h,h);
    cout << ")";
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i = 0; i<n;i++){
    for(int j = 0; j<n;j++){
        cin >> arr[i][j];
    }
  }
  func(0,0,n);
}
