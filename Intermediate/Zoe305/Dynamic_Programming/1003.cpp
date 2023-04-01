#include <bits/stdc++.h>
using namespace std;

int fibo[42];
int Z[1000006];
int O[1000006];
int T;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    Z[0] = 1;
    Z[1] = 0;
    O[0] = 0;
    O[1] = 1;
    fibo[0] = Z[1] + O[0];
    fibo[1] = Z[0] + O[1];
    
    while(T--){
        int N;
        cin >> N;
        for(int i = 2; i <= N; i++){
            Z[i] = Z[i-1] + Z[i-2];
            O[i] = O[i-1] + O[i-2];
            fibo[i] = Z[i] + O[i];
        }
        cout << Z[N] << " " << O[N] << '\n';
    }
    //0 넣을 때와 1 넣을 때 배열을 따로 만들어서 피보 배열에 넣었는데 이차원배열로 넣었어도 됐을 듯..?
}