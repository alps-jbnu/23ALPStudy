#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int M, N, L;
vector<pair<int, int>> animals;
vector<int> shooting_points;

bool bisearch(int st, int en, int animal_idx) {
    if(st>en) return false;
    int mid = (st+en)/2;
    int shooting_point = shooting_points[mid];
    auto animal = animals[animal_idx];
    auto dis = abs(shooting_point - animal.first) + animal.second;
    if(dis<=L) return true;
    else {
        if(shooting_point < animal.first) return bisearch(mid+1, en, animal_idx);
        else return bisearch(st, mid-1, animal_idx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>M>>N>>L;
    for(int i{}; i<M; i++) {
        int x;
        cin>>x;
        shooting_points.push_back(x);
    }
    for(int i{}; i<N; i++) {
        int x, y;
        cin>>x>>y;
        animals.push_back({x,y});
    }
    sort(shooting_points.begin(), shooting_points.end());

    int catched = 0;
    for(int i{}; i<N; i++) {
        if(bisearch(0, M-1, i)) catched++;
    }

    cout<<catched;

    return 0;
}