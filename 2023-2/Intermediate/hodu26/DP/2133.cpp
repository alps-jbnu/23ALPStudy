#include <bits/stdc++.h>

using namespace std;

int tilemap[33];

// T[N] = T[N-2]*T[2] + (T[N-4]*2) N-4==0이 될때까지 더하기...  -> T[N-4]*2 == T[4]~ 나오는 특수한 2개의 경우 고려

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N;

    cin >> N;

    if (N%2 == 0){
        tilemap[0] = 1;
        tilemap[2] = 3;

        for (int i=4; i<=N; i+=2){
            tilemap[i] = tilemap[i-2]*tilemap[2];

            for (int j=i; j>=4; j-=2){
                tilemap[i] += tilemap[j-4]*2;
            }
        }
    }
    
    cout << tilemap[N];

    return 0;
}
