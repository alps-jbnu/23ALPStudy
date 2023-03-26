#include <iostream>
#include <vector>
using namespace std;

int N, I, M;
vector<pair<int, int>> fishes;
int ans;

int left_top(pair<int, int> st, pair<int, int> net) {
    pair<int, int> en = {st.first + net.first, st.second + net.second};
    if(st.first < 1 || st.second < 1) return 0;
    if(en.first > N || en.second > N) return 0;

    int ret = 0;
    for(int i{}; i<fishes.size(); i++) {
        auto cur = fishes[i];
        if(st.first <= cur.first && cur.first <= en.first && st.second <= cur.second && cur.second <= en.second) ret++;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>I>>M;

    for(int i{}; i<M; i++) {
        pair<int, int> fish;
        cin>>fish.first>>fish.second;
        fishes.push_back(fish);
    }

    for(int i{}; i<M; i++) {
        pair<int, int> fish = fishes[i];
        pair<int, int> net{0, I/2};
        for(int j{}; j<I/2-1; j++) {
            net.first++;
            net.second--;
            for(int k{fish.first-net.first}; k<=fish.first; k++) {
                for(int l{fish.second-net.second}; l<=fish.second; l++) {
                    pair<int, int> cur = {k, l};
                    ans = max(ans, left_top(cur, net));
                }
            }
        }
    }

    cout<<ans;

    return 0;
}