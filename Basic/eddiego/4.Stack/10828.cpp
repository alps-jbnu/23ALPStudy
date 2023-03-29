#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> S;

    while (n--){
        string str;
        cin >> str;
        if(str=="push"){
            int p;
            cin >> p;
            S.push(p);
        }
        else if(str=="pop"){
            if(S.empty())
                cout << -1 << "\n";
            else{
                cout << S.top() << "\n";
                S.pop();
            }
        }
        else if(str=="size")
            cout << S.size() << "\n";
        else if(str=="empty")
            cout << (int)S.empty() << "\n";
        else{
            if(S.empty())
                cout << -1 << "\n";
            else
                cout <<S.top() << "\n";
        }
    }
}