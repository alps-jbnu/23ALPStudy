#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    array<int, 7> arr = { 0 };
    vector<int> odd;
    for (int i = 0; i < 7; i++)
        cin >> arr[i];

    int count = 0;
    for (int i = 0; i < 7; i++)
        if (arr[i] % 2 == 1)
        {
            odd.push_back(arr[i]);
            count++;
        }

    if (count == 0)
    {
        cout << -1 << endl;
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < odd.size(); i++)
        sum += odd[i];

    cout << sum << endl;

    sort(odd.begin(), odd.end());

    cout << odd[0] << endl;

    return 0;
}