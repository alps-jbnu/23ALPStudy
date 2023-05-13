#include <iostream>
#include <cstring>
using namespace std;

string bridges[2];
string scroll;
int dp[2][101][21];

int noc(int bridge, int bridge_idx, int scroll_idx) {
    if(scroll_idx == scroll.length()) return 1;

    int& cur = dp[bridge][bridge_idx][scroll_idx];
    if(cur == -1) {
        cur = 0;
        for(int i{bridge_idx}; i< bridges[0].length(); i++) {
            if(bridges[bridge][i] == scroll[scroll_idx]) cur += noc(!bridge, i+1, scroll_idx+1);
        }
    }

    return cur;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>scroll;
    for(int i{}; i<2; i++) {
        cin>>bridges[i];
    }
    memset(dp, -1, sizeof(dp));
    cout<<noc(0, 0, 0) + noc(1, 0, 0);

    return 0;
}