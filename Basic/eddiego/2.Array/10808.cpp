#include "bits/stdc++.h"
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    cin >> s;

    for(char a = 'a'; a<='z'; a++){
        int cnt = 0;
        for(auto c : s)
            if(a==c)
                cnt++;
        cout << cnt << ' ';
    }
}