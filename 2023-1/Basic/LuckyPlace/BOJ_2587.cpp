#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main(void)
{
    array<int, 5> arr = { 0 };

    for (int i = 0; i < 5; i++)
        cin >> arr[i];

    int sum = 0;
    for (int i = 0; i < 5; i++)
        sum += arr[i];

    cout << sum / 5 << endl;

    sort(arr.begin(), arr.end());

    cout << arr[2] << endl;

    return 0;
}