#define INT_MAX 2147483648
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//pair = {like, alcohol}

int N, M, K;

struct cmp {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        if(a.first == b.first) return a.second > b.second;
        else return a.first < b.first;
    }  
};
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

long long ans{INT_MAX};

void bisearch(long long st, long long en) {
    if(st>en) {
        if(ans == INT_MAX) ans = -1;
        return;
    }

    long long mid{(st+en)/2}; // liver
    int sum{}, cnt{};
    vector<pair<int, int>> temp;
    while(!pq.empty()) {
        auto cur{pq.top()};
        pq.pop();
        temp.push_back(cur);

        if(cur.second <= mid) {
            sum += cur.first;
            cnt += 1;
        }
        if(cnt == N) break;
    }
    for(int i{}; i<temp.size(); i++) pq.push(temp[i]);
    
    if(sum >= M && cnt == N) {
        ans = min(ans, mid);
        bisearch(st, mid-1);
    }
    else {
        bisearch(mid+1, en);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M>>K;
    long long en{};
    for(int i{}; i<K; i++) {
        long long like, alcohol;
        cin>>like>>alcohol;
        pq.push({like, alcohol});
        en = max(en, alcohol);
    }
    bisearch(1, en+1);
    cout<<ans;
    //cout<<pq.top().first<<","<<pq.top().second<<"\n";

    return 0;
}