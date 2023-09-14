#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long ans=0;
int cnt = -1; // 방문 0부터 
int N, r, c;

int div(int N, int a, int b){
    if(N==2){
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                cnt++;
                int x = a+i;
                int y = b+j;
                if(x == r && y == c){
                    cout << cnt;
                    return 0;
                }
            }
        }
    }
    if(r<a+N/2 && c<b+N/2){
        div(N/2, a, b);
    }
    else if(r<a+N/2 && c>= b+N/2){
        cnt += pow(N/2, 2);
        div(N/2,a,b+N/2);
    }
    else if(r>=a+N/2 && c<b+N/2){
        cnt += 2 * pow(N/2,2);
        div(N/2, a+N/2, b);
    }
    else{
        cnt += 3*pow(N/2,2);
        div(N/2, a+N/2, b+N/2);
    }
    return 0;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> r >> c;

    N = pow(2,N); // 사각형이 제곱으로 늘어남
    div(N,0,0);
}   
