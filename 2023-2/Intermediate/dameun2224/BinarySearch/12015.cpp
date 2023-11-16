#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<climits>
using namespace std;

int n, m;
vector<int> v;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> m;
        if (v.empty() || v.back() < m) v.push_back(m);
        else *lower_bound(v.begin(), v.end(), m) = m;
    }

    cout << v.size() << '\n';

    return 0;
}
