#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int N;
deque<int> dq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N;
    for(int i{}; i<N; i++) {
        int L;
        cin>>L;
        dq.push_back(L);
    }

    sort(dq.begin(), dq.end());
    int cnt = 0;
    while(dq.size() > 1) {
        dq[0]--;
        cnt++;
        if(dq[0] == 0) dq.pop_front();
        int back[2];
        back[0] = dq[dq.size()-1];
        dq.pop_back();
        back[1] = dq[dq.size()-1];
        dq.pop_back();
        dq.push_back(back[0]+back[1]+1);
    }
    cout<<cnt;
    
    return 0;
}