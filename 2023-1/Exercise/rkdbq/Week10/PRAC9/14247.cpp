#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
    bool operator()(pair<long long, long long> a, pair<long long, long long> b) {
        if(a.first == b.first) return a.second < b.second;
        else return a.first < b.first;
    }
};

priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, cmp> pq;
long long n{}, h[100001], a[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    for(int i{}; i<n; i++) cin>>h[i];
    for(int i{}; i<n; i++) cin>>a[i];
    for(int i{}; i<n; i++) pq.push({a[i], h[i]});

    long long ans{};
    while(!pq.empty()) {
        ans += pq.top().first*(pq.size()-1) + pq.top().second;
        pq.pop();
    }
    cout<<ans;

    return 0;
}