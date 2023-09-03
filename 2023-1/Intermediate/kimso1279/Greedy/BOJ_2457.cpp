#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    vector<pair<int, int>> f;

    for(int i=0; i<n; i++){
        int stM, stD, enM, enD;
        cin >> stM >> stD >> enM >> enD;

        int st = stM * 100 + stD;
        int en = enM * 100 + enD;
        f.push_back({st,en});
    }
    
    int t = 301, cnt = 0;

    while(t < 1201){
        int nxt = t;

        for(int i=0; i < n; i++){
            if(f[i].first <= t && f[i].second > nxt) nxt = f[i].second;
        }

        if(nxt == t){
            cout << 0;
            return 0;
        }
        cnt++;
        t = nxt;
    }
    cout << cnt;
}

