#include <iostream>
#include <stack>
using namespace std;

string str;

string isPPAP() {
    stack<char> S;
    for(int i{}; i<str.length(); i++) {
        if(S.size()>=3 && S.top() == 'A' && str[i] == 'P') {
            S.pop();
            char second = S.top();
            S.pop();
            char first = S.top();
            S.pop();

            if(first == 'P' && second == 'P') S.push('P');
            else {
                S.push(first);
                S.push(second);
                S.push('A');
                S.push('P');
            }
        }
        else S.push(str[i]);
    }

    if(S.size() == 1 && S.top() == 'P') return "PPAP";
    else return "NP";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>str;
    cout<<isPPAP();
    
    return 0;
}