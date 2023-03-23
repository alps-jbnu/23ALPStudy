#include <iostream>
#include <array>
using namespace std;

void print(array<int, 20>& arr)
{
	for (auto& e : arr)
		cout << e << ' ';
	cout << endl;
}

int main(void)
{
	array<int, 20> arr;

	for (int i = 1; i <= 20; i++)
		arr[i - 1] = i;

	int start, end;
	for (int j = 0; j < 10; j++)
	{
		cin >> start >> end;
		int interval = end - start;
		end--;
		start--;
		if ((interval % 2) == 1)
		{
			if ((interval / 2) == 0)
			{
				int temp;
				temp = arr[end];
				arr[end] = arr[start];
				arr[start] = temp;
				start++;
				end--;
				continue;
			}
			for (int i = 0; i < (interval / 2) + 1; i++)
			{
				int temp;
				temp = arr[end];
				arr[end] = arr[start];
				arr[start] = temp;
				start++;
				end--;
			}
		}
		else if (interval == 0)
			continue;
		else if ((interval % 2) == 0)
		{
			for (int i = 0; i < (interval / 2); i++)
			{
				int temp;
				temp = arr[end];
				arr[end] = arr[start];
				arr[start] = temp;
				start++;
				end--;
			}
		}
	}
	print(arr);

	return 0;
}