#include <bits/stdc++.h>
using namespace std;

int N;
int p[1004];
int sum;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> p[i];
    sort(p, p+N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i; j++){
            sum += p[j];
        }
    }

    cout << sum;
}
/*
배열 작은 순으로 정렬하고,
N의 값이 작으니 이중포문으로 풀어도 지장 없다고 생각했음.
마지막 사람의 시간이 안 더해져서,
그냥 j < i를 j <= i로 바꿨더니 정답이 됨.
생각해 보면 본인 시간도 더해야 하는데 j < i로 하면 본인 시간이 안 더해짐.
*/