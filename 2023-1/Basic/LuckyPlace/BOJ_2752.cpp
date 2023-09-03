#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main(void)
{
    array<int, 3> arr = { 0 };
    for (int i = 0; i < 3; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    for (int i = 0; i < 3; i++)
        cout << arr[i] << ' ';

    return 0;
}