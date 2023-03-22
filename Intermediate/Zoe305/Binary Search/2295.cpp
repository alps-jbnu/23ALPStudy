#include <bits/stdc++.h>

using namespace std;

int N;
int A[1005];
vector<int> two;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A, A+N);

    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            two.push_back(A[i]+A[j]);
        }
    }
    sort(two.begin(), two.end());

    for(int i = N-1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(binary_search(two.begin(), two.end(), A[i]-A[j])){
                cout << A[i];
                return 0;
            }
        }
    }
}