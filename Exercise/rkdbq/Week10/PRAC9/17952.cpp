#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Assignment {
    public:
    int priority;
    int score;
    int t;
    Assignment(int p, int s, int t) {
        priority = p;
        score = s;
        this->t = t;
    }
};

struct cmp
{
    bool operator()(Assignment a, Assignment b) {
        return a.priority < b.priority;
    }
};

int N, total;
priority_queue<Assignment, vector<Assignment>, cmp> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N;
    for(int i{}; i<N; i++) {
        int p, s, t;
        cin>>p;
        if(p==1) {
            cin>>s>>t;
            pq.push(Assignment(i, s, t));
        }
        if(!pq.empty()) {
            auto tmp{pq.top()};
            pq.pop();
            tmp.t--;
            if(tmp.t>0) pq.push(tmp);
            else total += tmp.score;
        }
    }
    cout<<total<<"\n";

    return 0;
}