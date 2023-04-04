#include <iostream>
#include <algorithm>
using namespace std;

int N, X;
pair<int, int> taste[100001];

bool cmp(pair<int, int> a, pair<int, int> b) {
        return (a.first - a.second) > (b.first - b.second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>X;
    for(int i{}; i<N; i++) {
        int A, B;
        cin>>A>>B;
        taste[i] = {A, B};
    }

    int curTaste = 0;
    int curPrice = 0;
    sort(taste, taste + N, cmp);
    for(int i{}; i<N; i++) curTaste+=taste[i].second;
    curPrice = 1000*N;

    for(int i{}; i<N; i++) {
        int gap = taste[i].first - taste[i].second;
        if(gap > 0 && curPrice + 4000 <= X) {
            curTaste += gap;
            curPrice += 4000;
        }
        else break;
    }

    cout<<curTaste;

    return 0;
}