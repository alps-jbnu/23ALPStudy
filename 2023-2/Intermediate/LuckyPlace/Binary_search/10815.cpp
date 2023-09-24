#include <iostream>
using namespace std;

int A[500'005];
int tmp[500'005];

bool binary_search(int target, int n)
{
	int start = 0;
	int end = n - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (A[mid] < target)
			start = mid + 1;
		else if (A[mid] > target)
			end = mid - 1;
		else     // A[mid] == target
			return true;
	}
	return false;
}

void merge(int start, int end)
{
	int mid = (start + end) / 2;
	int lidx = start;
	int ridx = mid;
	for (int i = start; i < end; i++)
	{
		if (mid == lidx)
			tmp[i] = A[ridx++];
		else if (end == ridx)
			tmp[i] = A[lidx++];
		else if (A[lidx] <= A[ridx])
			tmp[i] = A[lidx++];
		else
			tmp[i] = A[ridx++];
	}
	for (int i = start; i < end; i++)
		A[i] = tmp[i];
}

void merge_sort(int start, int end)
{
	if (end == (start + 1))
		return;
	int mid = (start + end) / 2;
	merge_sort(start, mid);
	merge_sort(mid, end);
	merge(start, end);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i];
	merge_sort(0, n);
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int in;
		cin >> in;
		if (binary_search(in, n))
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}

	return 0;
}
