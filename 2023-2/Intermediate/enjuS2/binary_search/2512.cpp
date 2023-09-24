#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<climits>
using namespace std;

vector<int> arr;
int n, m;
long long ans;

void func(int st, int en) {
    int mid = (st + en) / 2;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > mid) {
            sum += mid;
        }
        else {
            sum += arr[i];
        }
    }

    if (st > en) return;

    if (sum <= m) {
        ans = mid;
        func(mid + 1, en);
    }
    else {
        func(st, mid - 1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
        mx = max(mx, input);
    }

    cin >> m;

    func(1, mx);

    cout << ans;

    return 0;
}
