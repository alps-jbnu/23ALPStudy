#include <iostream>
using namespace std;

string number;
int dp[41];

void func() {
    dp[0] = 1;
    for(int i{1}; i<number.length(); i++) {
        if(number[i] != '0') dp[i] += dp[i-1];
        if(number[i-1] == '0') continue;
        int cur {(number[i-1]-'0')*10+(number[i]-'0')};
        if(cur <= 34) {
            if(i > 1) dp[i] += dp[i-2];
            else (number[i] == '0') ? dp[i] = 1 : dp[i] = 2;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>number;
    func();
    cout<<dp[number.length()-1];
    
    return 0;
}