#include<bits/stdc++.h>
using namespace std;

int point[155];
bool check[155];
int num, result;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> point[i];
    }

    num = point[0];

	while (check[num] != true)
	{
		result++;
		check[num] = true;
		if (num == k)
		{
			cout << result;

			return 0;
		}
		num = point[num];

	}
	cout << "-1";

	return 0;
}