#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main(void) 
{
    array<int, 3> arr = { 0 };
    for (int i = 0; i < 3; i++)
        cin >> arr[i];

    if (arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[0]) 
    {
        cout << 10000 + (arr[0] * 1000) << endl;
        return 0;
    }
    else if (arr[0] == arr[1]) 
    {
        cout << 1000 + (arr[0] * 100) << endl;
        return 0;
    }
    else if (arr[1] == arr[2]) 
    {
        cout << 1000 + (arr[1] * 100) << endl;
        return 0;
    }
    else if (arr[2] == arr[0]) {
        cout << 1000 + (arr[2] * 100) << endl;
        return 0;
    }
    else
    {
        sort(arr.begin(), arr.end());
        cout << arr[2] * 100 << endl;
    }

    return 0;
}
