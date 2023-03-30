#include <bits/stdc++.h>
using namespace std;

int N;
queue<int> q;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; ++i) q.push(i);
    while(q.size() != 1){
        q.pop();
        int tmp = q.front();
        q.push(tmp);
        q.pop();
    }
    cout << q.front();
}