#define MAX 100001
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int a[MAX];
long long ans;

int distance(int a, int b) {
    return abs(a-b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N;
    for(int i{}; i<N; i++) cin>>a[i];
    sort(a, a+N);

    int cur = 1;
    ans += (a[0]-cur);
    for(int i{1}; i<N; i++) {
        if(cur == a[i]) continue;
        if(cur+1 == a[i]) {
            cur += 1;
            continue;
        }
        ans += (a[i]-(cur+1));
        cur += 1;
    }

    cout<<ans;

    return 0;
}