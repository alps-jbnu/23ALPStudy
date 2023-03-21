#include <bits/stdc++.h>

using namespace std;

int N;
int M;
int Narr[500005];
int Marr[500005];


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> Narr[i];

    cin >> M;
    for(int i = 0; i < M; i++) cin >> Marr[i];
    sort(Narr, Narr+N);

    for(int i = 0; i < M; i++) cout << binary_search(Narr, Narr+N, Marr[i]) << ' ';
}