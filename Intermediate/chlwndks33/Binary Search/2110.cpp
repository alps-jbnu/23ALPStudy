#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans=-1;
    int n,m,a;
    vector<int> vec;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(),vec.end());
    int st = 1;
    int en = vec.back() - vec.front();
    while(st<=en) {
        int mid =  (st + en) /2;
        int num = 1;
        cout << "st " << st << "en " << en << "mid " << mid << '\n';
        int start = vec[0];
        for(int i=1; i<n; i++) {
            int check = vec[i];
            if(check-start >= mid) {
                num++;
                start = check;
            }
        }
        if(num >= m) {
            ans = max(ans,mid);
            st = mid+1;
        }
        else {
            en = mid-1;
        }
        
    }
    cout << ans;
}