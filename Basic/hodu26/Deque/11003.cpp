#include <bits/stdc++.h>

using namespace std;

#define MX_A 1000000001
#define MX_i 5000001

deque<pair<int,int>> checkMin;   // <D_min,i> -> [... ,<nxt_min,i>,<cur_min,i>]

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int N,L,A;

    cin >> N >> L;

    for (int i=1;i<=N;i++){
        cin >> A;

        if (!checkMin.empty() && checkMin.back().second < i-L+1){
            checkMin.pop_back();
        }

        if (!checkMin.empty() && A <= checkMin.back().first){
            while (!checkMin.empty() && checkMin.back().second <= i){
                checkMin.pop_back();
            }
            checkMin.push_back(make_pair(A,i));
        }
        else {
            while (!checkMin.empty() && A <= checkMin.front().first){
                checkMin.pop_front();
            }
            checkMin.push_front(make_pair(A,i));
        }

        cout << checkMin.back().first << ' ';  // checkMin.back().first == cur_min
    }

    return 0;
}
