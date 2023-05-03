// baekjoon - 1074번 Z

#include <iostream>
#include <cmath>
using namespace std;

int n,r,c;
int ans;

int parition(int startr, int startc, int n) {  //몇번 영역인지 확인하는 함수
    int half = (int)pow(2,n-1);
    if(r< startr+half) {
        if(c < startc+half) {
            return 0;
        }
        else {
            return 1;
        }
    }
    else {
        if(c < startc+half) {
            return 2;
        }
        else {
            return 3;
        }
    }
}

void func(int startr, int startc, int start, int n) {
    if(n==1) { //base case
        ans = start+parition(startr,startc,n);
        return;
    }
    int pown = (int)pow(4,n-1);
    int half = (int)pow(2,n-1);
    switch(parition(startr,startc,n))
    {
        case 0:
            func(startr, startc, start,n-1);
            break;
        case 1:
            func(startr,startc+half,start+pown,n-1);
            break;
        case 2:
            func(startr+half,startc,start+pown*2,n-1);
            break;
        case 3:
            func(startr+half,startc+half,start+pown*3,n-1);
            break;
    }
    return;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> r >> c;
    func(0,0,0,n);
    cout << ans;

}