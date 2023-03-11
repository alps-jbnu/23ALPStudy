#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Cow {
    public:
    int s;
    int a;
    int t;
    Cow(int s, int a, int t) {
        this->s = s;
        this->a = a;
        this->t = t;
    }
};

int N;

class arrive_cmp {
    public:
    bool operator() (Cow a, Cow b) {
        return a.a > b.a;
    }
};

class seniority_cmp {
    public:
    bool operator() (Cow a, Cow b) {
        return a.s > b.s;
    }
};

priority_queue<Cow, vector<Cow>, arrive_cmp> cows;
priority_queue<Cow, vector<Cow>, seniority_cmp> s;

int solve() {
    int curTime = 0;
    int cowWaiting = 0;

    while(!cows.empty() || !s.empty()) {
        if(s.empty() && !cows.empty()) {
            if(curTime <= cows.top().a) curTime = cows.top().a;
            curTime += cows.top().t;
            cows.pop();
        }
        while(!cows.empty() && cows.top().a <= curTime) {
            s.push(cows.top());
            cows.pop();
        }
        if(!s.empty()) {
            cowWaiting = max(curTime - s.top().a, cowWaiting);
            curTime += s.top().t;
            s.pop();
        }
    }

    return cowWaiting;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N;
    for(int i{}; i<N; i++) {
        int a, t;
        cin>>a>>t;
        cows.push(Cow(i, a, t));
    }
    cout<<solve();

    return 0;
}