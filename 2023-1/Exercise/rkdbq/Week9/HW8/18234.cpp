#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N, T;
vector<pair<long long, long long>> carrots;
long long ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>T;
    for(int i{}; i<N; i++) {
        int w, p;
        cin>>w>>p;
        carrots.push_back({p, w});
    }
    sort(carrots.begin(), carrots.end(), greater<pair<long long, long long>>());
    for(int i{}; i<N; i++) {
        ans += carrots[i].second + carrots[i].first*(T-(i+1));
    }
    cout<<ans;

    return 0;
}