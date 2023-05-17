#include <iostream>
using namespace std;

const int MAX = 7;

int N, M;
int arr[MAX];

void func(int idx)
{
	if (idx == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = 1; i <= N; i++)
	{
		arr[idx] = i;
		func(idx + 1);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	func(0);

	return 0;
}