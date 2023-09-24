#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<climits>
using namespace std;

int n, m, l;
vector<int> vec;

bool chk(int mid) {
    int cnt = 0;
    for (int i = 1; i < vec.size(); i++) {
        int dist = vec[i] - vec[i - 1];
        cnt += dist / mid;
        if (dist % mid == 0) {
            cnt--;
        }
    }
    return cnt > m;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> l;
    vec.push_back(0);
    vec.push_back(l);
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        vec.push_back(input);
    }
    sort(vec.begin(), vec.end());

    int st = 1;
    int en = l;
    int mid = 0;
    int ans;
    while (st <= en) {
        mid = (st + en) / 2;
        if (chk(mid)) {
            st = mid + 1;
        }
        else {
            ans = mid;
            en = mid - 1;
        }
    }

    cout << ans;
    return 0;
}
