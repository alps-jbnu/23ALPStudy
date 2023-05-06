#include <iostream>
using namespace std;

void star(int i, int j, int n){
    if((i/n)%3 == 1 && (j/n)%3 == 1){ // 가운데는 비어있음, ex) (1,1)
        cout << ' ';
    }
    else {
        if(n/3 == 0) cout << "*";
        else star(i,j,n/3);
    }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i = 0;i<n;i++){
    for(int j = 0; j<n;j++){
        star(i, j, n);
    }
    cout << "\n";
  }
}
