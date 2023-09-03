// baekjoon 1780번 종이의 개수

#include <iostream>
using namespace std;
int n;
int arr[2188][2188];
int ans[3];

void func(int y, int x, int n) {
    int value = arr[y][x];
    if(n==1) {  //base case: n=1 일때 
        ans[value+1]++;
        return;
    }
    for(int i = y; i<y+n; i++) {
        for(int j= x; j<x+n; j++) {
            if(value != arr[i][j]) {
                int nextn= n/3;
                for(int i=0; i<3; i++) {   //9개로 쪼겜
                    for(int j=0; j<3; j++) {
                        func(y+i*nextn,x+j*nextn,nextn);
                    }
                }
                return;
            }
        }
    }
    ans[value+1]++;
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    func(0,0,n);
    for(auto e:ans) cout << e << '\n';
    return 0;
}