#include <bits/stdc++.h>        
using namespace std;

int n;
void hanoi(int a, int b, int k){
  if (k == 1) {
    cout << a << " "<< b << "\n";
    return;
  }
  hanoi(a,6-a-b,k-1); //6에서 a와 b를 빼면 나머지 번호가 나온다.
  cout << a << " " << b << "\n";
  hanoi(6-a-b,b,k-1);
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  cout<< (1<<n) -1 << "\n"; //1<<n = 2^n
  hanoi(1,3,n);
}
