#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int price_per_weight[101];
int weight[2001];
int total;

int in_and_out[4002];
int parked[101];
queue<int> not_in_yet;

int smallest_idx() {
    for(int i{1}; i<=N; i++) {
        if(parked[i] == 0) return i;
    }
    return -1;
}

int find_idx(int w) {
    for(int i{1}; i<=N; i++) {
        if(parked[i] == w) return i;
    }
    return -1;
}

void solve() {
    for(int i{1}; i<=2*M; i++) {
            int cur = in_and_out[i];
            if(cur>0) {
                int s_idx = smallest_idx();
                if(s_idx == -1) {
                    not_in_yet.push(cur);
                    continue;
                }
                else parked[s_idx] = cur;
                //cout<<pq.top().first<<", "<<pq.top().second<<"\n";
            }
            else {
                int parked_idx= find_idx(-cur);
                total += price_per_weight[parked_idx] * weight[-cur];
                parked[parked_idx] = 0;
                if(!not_in_yet.empty()) {
                    parked[parked_idx] = not_in_yet.front();
                    not_in_yet.pop();
                    //cout<<pq.top().first<<", "<<pq.top().second<<"\n";
                }
            }
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M;
    for(int i{1}; i<=N; i++) {
        cin>>price_per_weight[i];
    }
    for(int i{1}; i<=M; i++) {
        cin>>weight[i];
    }
    for(int i{1}; i<=2*M; i++) {
        cin>>in_and_out[i];
    }
    solve();

    cout<<total;

    return 0;
}