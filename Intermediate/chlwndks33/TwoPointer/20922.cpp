#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int num[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans =0;
    int n,m,a;
    vector<int> vec;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> a;
        vec.push_back(a);
    }
    int en = 0;
	for (int st = 0; st < n; st++) {
		while (en < n && num[vec[en]] < m) {
			num[vec[en]]++;
			en++;
		}
		ans = max(ans, en - st);
		if (en == n) break;
		num[vec[st]]--;
	}
	cout << ans << endl;

	return 0;
}