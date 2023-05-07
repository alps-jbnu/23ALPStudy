#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int T,n,nxt, solo=0;

    cin >> T;

    while (T--){
        cin >> n;

        int choose[n+3] = {};
        int chosen[n+3] = {};

        for (int i=1;i<=n;i++){
            cin >> choose[i];
        }

        for (int i=1;i<=n;i++){
            deque<int> dq;

            if (chosen[i] == 0){
                dq.push_back(i);
                chosen[i] = 1;
                nxt = choose[i];

                while (chosen[nxt] == 0){
                    chosen[nxt] = 1;
                    dq.push_back(nxt);
                    nxt = choose[nxt];
                }

                while (!dq.empty() && dq.front() != nxt){
                    dq.pop_front();
                    solo++;
                }
            }
            if (i == n && dq.front() != nxt){
                solo += dq.size();
            }

            dq.clear();
        }

        cout << solo << '\n';

        solo = 0;
    }

    return 0;
}
