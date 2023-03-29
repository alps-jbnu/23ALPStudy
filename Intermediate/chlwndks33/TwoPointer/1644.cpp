#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<bool> v(n + 1, true);

    for (int i = 2; i <= n; i++)
    {
        if (v[i])
        {
            for (int j = i * 2; j <= n; j += i)
            {
                v[j] = false;
            }
        }
    }
    vector<int> prime;
    for (int i = 2; i <= n; i++)
    {
        if (v[i])
        {
            prime.push_back(i);
        }
    }
    int s = 0, e = 0;
	int sum = 0;
	int ans = 0;
	while (1) {
		if (sum > n) {
			sum -= prime[s];
			s++;
		}
		else if(sum<n){
			if (e >= prime.size()) break;
			sum += prime[e];
			e++;
		}
		else {
			ans++;
			if (e >= prime.size()) break;
			sum += prime[e];
			e++;
		}
	}
	cout << ans;

	return 0;
}
