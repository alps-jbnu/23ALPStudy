#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie();

    int N,a;

    cin >> N;

    stack<int> A;
    stack<int> bigNum;
    stack<int> NGE;

    for (int i=0;i<N;i++){
        cin >> a;
        A.push(a);
    }

    while (!A.empty()){
        if (bigNum.empty()){
            NGE.push(-1);
            bigNum.push(A.top());
            A.pop();
            continue;
        }

        if (bigNum.top() > A.top()){
            NGE.push(bigNum.top());
            bigNum.push(A.top());
            A.pop();
        }
        else {
            bigNum.pop();
        }
    }

    while (!NGE.empty()){
        cout << NGE.top() << ' ';
        NGE.pop();
    }

    return 0;
}
