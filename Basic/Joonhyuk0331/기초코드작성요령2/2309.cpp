#include <iostream>
#include <cstdlib>
using namespace std;

int compare(const void* a, const void* b)
{
	const int* x = (int*)a;
	const int* y = (int*)b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;

	return 0;
}

int main()
{
	int arr[10] = { 0, };
	int sum = 0;
	int cnt = 0;
	for (int i = 1; i <= 9; i++) cin >> arr[i];
	qsort(arr, 10, sizeof(int), compare);
	for (int i = 1; i <= 9; i++) sum += arr[i];
	for (int i = 1; i <= 8; i++) {
		for (int j = i + 1; j <= 9; j++)
		{
			if (sum - arr[i] - arr[j] == 100)
			{
				arr[i] = 0;
				arr[j] = 0;
				cnt++;
				break;
			}
		}
		if (cnt)
			break;
	}
	for (int i = 1; i <= 9; i++)
	{
		if (arr[i] != 0)
			cout << arr[i] << '\n';
	}
	return 0;
}
