#include <bits/stdc++.h>
using namespace std;

int K, ans = 0;
stack<int> s;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K;
    while(K--){
        int n;
        cin >> n;
        if(n == 0)
            s.pop();
        else
            s.push(n);
    }

    while(!s.empty()){
        ans += s.top();
        s.pop();
    }
    cout << ans;
}