#include <iostream>
#include <stack>
using namespace std;

int n;
string str;
bool check[200001];
stack<pair<int, char>> s;

int max_cnt() {
    int ans{}, cur{};
    for(int i{}; i<n; i++) {
        if(check[i]) cur++;
        else {
            ans = max(ans, cur);
            cur = 0;
        }
    }
    ans = max(ans, cur);
    return ans;
}

int find_longest(string str) {
    int ans, cnt;
    ans = cnt = 0;
    for(int i{}; i<str.length(); i++) {
        char cur{str[i]};
        if(cur == '(') {
            s.push({i, cur});
        }
        else if(!s.empty()) {
            check[s.top().first] = check[i] = true;
            s.pop();
        }
    }
    ans = max_cnt();
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    cin>>str;
    cout<<find_longest(str);

    return 0;
}