#include <bits/stdc++.h>

using namespace std;

int N;
int X[1000005];
vector<int> v1, v2;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> X[i];
        v1.push_back(X[i]);
    }
    sort(v1.begin(), v1.end());
    for(int i = 0; i < N; i++){
        if(i == 0 || v1[i-1] != v1[i]) v2.push_back(v1[i]);
    }

    for(int i = 0; i < N; i++){
        cout << lower_bound(v2.begin(), v2.end(), X[i]) - v2.begin() << " ";
    }
}