#include <bits/stdc++.h>

using namespace std;

deque<int> deq;

int main(){
    ios::sync_with_stdio(0);cin.tie();

    int N,X;
    string order;

    cin >> N;

    while (N--){
        cin >> order;

        if (deq.empty() && (order == "pop_front" || order == "pop_back" || order == "front" || order == "back")){
            cout << -1 << '\n';
            continue;
        }

        if (order == "push_front"){
            cin >> X;
            deq.push_front(X);
        }

        if (order == "push_back"){
            cin >> X;
            deq.push_back(X);
        }

        if (order == "pop_front"){
            cout << deq.front() << '\n';
            deq.pop_front();
        }

        if (order == "pop_back"){
            cout << deq.back() << '\n';
            deq.pop_back();
        }

        if (order == "size"){
            cout << deq.size() << '\n';
        }

        if (order == "empty"){
            cout << deq.empty() << '\n';
        }

        if (order == "front"){
            cout << deq.front() << '\n';
        }

        if (order == "back"){
            cout << deq.back() << '\n';
        }
    }

    return 0;
}
