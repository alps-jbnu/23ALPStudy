#include <bits/stdc++.h>
const int MAX = 1000000 + 1;
using namespace std;

int N;
long long result;
int arr[MAX];

void Merge(int* arr, int left, int mid, int right)
{
    int i = left, j = mid + 1, t = 1;
    int temp[MAX];

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[t++] = arr[i++];
        }
        else
        {
            result += mid - i + 1;
            temp[t++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[t++] = arr[i++];
    }
    while (j <= right)
    {
        temp[t++] = arr[j++];
    }

    i = left, t = 1;
    while (i <= right)
    {
        arr[i++] = temp[t++];
    }
}

void Merge_sort(int* arr, int left, int right)
{
    if (left < right)
    {
        int Mid = (left + right) / 2;
        Merge_sort(arr, left, Mid);
        Merge_sort(arr, Mid + 1, right);
        Merge(arr, left, Mid, right);
    }
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    result = 0;

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    Merge_sort(arr, 1, N);

    cout << result;

    return 0;
}