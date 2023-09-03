#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int cnt[30]={0, };
    cin >> s;
    for (int i = 0; i <s.length(); i++){
        cnt[s[i]-97]++;
    }
    for (int i = 0; i <26;i++) {
        cout << cnt[i] << " ";
    }
    return 0;
}
