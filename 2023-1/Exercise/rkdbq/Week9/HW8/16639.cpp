#define LLONG_MAX 9223372036854775807LL
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N;
string str;
pair<long long, long long> dp[21][21];

pair<long long, long long> cal(int st, int en) {
    if(dp[st][en].first != -LLONG_MAX || dp[st][en].second != LLONG_MAX) return dp[st][en];
    if(st==en) return dp[st][en] = {str[st] - '0', str[st] - '0'};
    pair<long long, long long> ret{-LLONG_MAX, LLONG_MAX};
    for(int i{st}; i<en; i+=2) {
        auto l{cal(st, i)}, r{cal(i+2, en)};
        if(str[i+1] == '+') {
            ret.first = max(ret.first, l.first+r.first);
            ret.first = max(ret.first, l.first+r.second);
            ret.first = max(ret.first, l.second+r.first);
            ret.first = max(ret.first, l.second+r.second);
            ret.second = min(ret.second, l.first+r.first);
            ret.second = min(ret.second, l.first+r.second);
            ret.second = min(ret.first, l.second+r.first);
            ret.second = min(ret.second, l.second+r.second);
        }
        else if(str[i+1] == '-') {
            ret.first = max(ret.first, l.first-r.first);
            ret.first = max(ret.first, l.first-r.second);
            ret.first = max(ret.first, l.second-r.first);
            ret.first = max(ret.first, l.second-r.second);
            ret.second = min(ret.second, l.first-r.first);
            ret.second = min(ret.second, l.first-r.second);
            ret.second = min(ret.first, l.second-r.first);
            ret.second = min(ret.second, l.second-r.second);
        }
        else if(str[i+1] == '*') {
            ret.first = max(ret.first, l.first*r.first);
            ret.first = max(ret.first, l.first*r.second);
            ret.first = max(ret.first, l.second*r.first);
            ret.first = max(ret.first, l.second*r.second);
            ret.second = min(ret.second, l.first*r.first);
            ret.second = min(ret.second, l.first*r.second);
            ret.second = min(ret.first, l.second*r.first);
            ret.second = min(ret.second, l.second*r.second);
        }
    }
    return dp[st][en] = ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i{}; i<21; i++) {
        for(int j{}; j<21; j++) {
            dp[i][j].first = -LLONG_MAX;
            dp[i][j].second = LLONG_MAX;
        }
    }

    cin>>N;
    cin>>str;
    cout<<cal(0, N-1).first<<"\n";

    return 0;
}