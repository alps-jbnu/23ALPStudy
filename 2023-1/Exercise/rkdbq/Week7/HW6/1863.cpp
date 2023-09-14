#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int n, ans;
stack<int> h;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    for(int i{}; i<n; i++) {
        pair<int, int> pos;
        cin>>pos.first>>pos.second;
        if(h.empty() || h.top()<pos.second) h.push(pos.second);
        else {
            while(!h.empty() && h.top()>=pos.second) {
                if(h.top()>pos.second) ans++;
                h.pop();
            }
            h.push(pos.second);
        }
    }
    while(!h.empty()) {
        if(h.top()!=0) ans++;
        h.pop();
    }
    
    cout<<ans;
    return 0;
}