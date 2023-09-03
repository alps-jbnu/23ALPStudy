#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,a;
    vector<int> vec;
    cin >> n >> m;
    long long ans = 0;
    for(int i=0; i<n; i++) {
        cin >> a;
        vec.push_back(a);
    }
    long long st = 1;
    long long en = *max_element(vec.begin(),vec.end());
    while(st<=en) {
        long long mid = (st+ en) / 2;
        int count = 0;
        for(int i=0; i<n; i++) {
            count +=vec[i] / mid;
        }
        if(count >=m) {
            if(ans < mid) {
                ans = mid;
            }
            st = mid+1;
        }
        else {
            en = mid-1;
        }

    }
    cout << ans;
}