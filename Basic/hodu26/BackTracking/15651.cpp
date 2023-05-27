#include <bits/stdc++.h>

using namespace std;

int seq[13];

void sequence_recursion(int N, int M, int floor){

    for (int i=1;i<=N;i++){
        seq[floor] = i;

        if (floor == M){
            for (int j=1;j<=M;j++){
                cout << seq[j] << ' ';
            }
            cout << '\n';
        }
        else {
            sequence_recursion(N,M,floor+1);
        }
    }

    return ;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N,M;

    cin >> N >> M;

    sequence_recursion(N,M,1);
    
    return 0;
}
