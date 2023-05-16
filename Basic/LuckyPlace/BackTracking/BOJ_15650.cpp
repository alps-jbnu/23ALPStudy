#include <iostream>
using namespace std;

int n, m;
bool is_used[9];
int arr[9];

void back_tracking(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << "\n";
		return;
	}
	// 이어지는 수가 앞에 수보다 작은 수가 나오면 안된다.
	int start = 1;					// k == 0 이면 start == 1
	if (k != 0)
		start = arr[k - 1] + 1;
	for (int i = start; i <= n; i++)
	{
		
		if (!is_used[i])
		{
			arr[k] = i;
			is_used[i] = true;
			back_tracking(k + 1);
			is_used[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	back_tracking(0);
	return 0;
}