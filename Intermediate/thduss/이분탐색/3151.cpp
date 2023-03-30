#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
  	cin.tie(0);

	int n, arr[10002];
	cin >> n;

	for(int i=0; i<n; i++) cin >> arr[i];
	sort(arr, arr+n);

	long long result = 0;

	for(int i=0; i<n-2; i++){
		for(int j=i+1; j<n-1; j++){
			int sum = arr[i] + arr[j];
			auto ub = upper_bound(arr+j+1, arr+n,-arr[i] -arr[j]);
			auto lb = lower_bound(arr+j+1, arr+n,-arr[i] -arr[j]);
			result += ub - lb;
		}
	}
	cout << result << "\n";
}
