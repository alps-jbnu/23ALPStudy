#include <bits/stdc++.h>

using namespace std;

int element[23];

int sum_recursion(int N, int S, int sum, int ans, int cur){
    if (cur != -1 && sum == S) ans++;

    for (int i=cur+1;i<N;i++){
        sum += element[i];

        ans = sum_recursion(N,S,sum,ans,i);

        sum -= element[i];
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N,S;

    cin >> N >> S;

    for (int i=0;i<N;i++){
        cin >> element[i];
    }

    cout << sum_recursion(N,S,0,0,-1);
    
    return 0;
}
