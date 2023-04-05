#include <bits/stdc++.h>

using namespace std;

queue<int> q;

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);

    int N,X;
    string order;

    cin >> N;

    while(N--){
        cin >> order;

        if (order == "push"){
            cin >> X;

            q.push(X);
        }

        if (order == "pop"){
            if (q.empty()){
                cout << -1 << '\n';
                continue;
            }
            cout << q.front() << '\n';
            q.pop();
        }

        if (order == "size"){
            cout << q.size() << '\n';
        }

        if (order == "empty"){
            cout << q.empty() << '\n';
        }

        if (order == "front"){
            if (q.empty()){
                cout << -1 << '\n';
                continue;
            }
            cout << q.front() << '\n';
        }

        if (order == "back"){
            if (q.empty()){
                cout << -1 << '\n';
                continue;
            }
            cout << q.back() << '\n';
        }
    }

    return 0;
}
