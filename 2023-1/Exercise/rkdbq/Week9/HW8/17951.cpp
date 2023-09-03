#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N, K;
int corrects[100001];

int bisearch(int st, int en) {
    int mid{(st+en)/2};
    if(st>en) return mid;
    int k{}, sum{};
    for(int i{1}; i<=N; i++) {
        sum += corrects[i];
        if(sum >= mid) {
            k += 1;
            sum = 0;
        }
    }
    if(k>=K) return bisearch(mid + 1, en);
    else return bisearch(st, mid - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>K;
    int en{};
    for(int i{1}; i<=N; i++) {
        cin>>corrects[i];
        en += corrects[i];
    }
    cout<<bisearch(0, en);

    return 0;
}