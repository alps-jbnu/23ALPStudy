#define MAX 1000000005
#define min_heap(type) priority_queue<type, vector<type>, greater<type>>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N, M, C;
vector<int> cows;
int answer = MAX;

bool check(int t) {
    vector<vector<int>> buses;
    for(int i{}; i < M; i++) {
        vector<int> bus;
        buses.push_back(bus);
    }

    int firstCow;
    int busCapacity = 0;
    int busCount = 1;
    for(int i{}; i < N; i++) {
        if(busCapacity == 0) {
            firstCow = cows[i];
            busCapacity++;
            continue;
        }
        if((busCapacity < C) && (cows[i] - firstCow <= t)) busCapacity++;
        else {
            busCount++;
            busCapacity = 1;
            firstCow = cows[i];
        }
    }
    return busCount <= M;
}

void bisearch(int st, int en) {
    if(st > en) return;
    int mid = (st + en) / 2;
    if(check(mid)) {
        answer = min(mid, answer);
        bisearch(st, mid - 1);
    }
    else bisearch(mid + 1, en);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M>>C;
    for(int i{}; i<N; i++) {
        int cow;
        cin>>cow;
        cows.push_back(cow);
    }

    sort(cows.begin(), cows.end());
    bisearch(0, MAX);
    cout<<answer<<'\n';
    
    return 0;
}