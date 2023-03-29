#include <bits/stdc++.h>
using namespace std;

int N;
int A[100005];
int M;

int bs(int num){
    int st = 0;
    int en = N-1;
    while(st <= en){
        int mid = (st+en)/2;
        if(A[mid] < num) st = mid+1;
        else if(A[mid] > num) en = mid-1;
        else return 1;
    }
    return 0;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A, A+N);

    cin >> M;
    while(M--){
        int num;
        cin >> num;
        cout << bs(num) << '\n';
    }
}