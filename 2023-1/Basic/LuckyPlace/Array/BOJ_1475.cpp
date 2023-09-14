#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    string str = to_string(N);

    int arr[10] = { 0 };
    for (int i = 0; i < str.size(); i++)
    {
        int t = static_cast<int>(str[i] - 48);
        if (t == 6 || t == 9)
        {
            if (arr[6] < arr[9])
                arr[6]++;
            else if (arr[6] > arr[9])
                arr[9]++;
            else
            {
                arr[t]++;
                continue;
            }
        }
        else
            arr[t]++;
    }
    sort(arr, arr+10, compare);
    cout << arr[0] << endl;

    return 0;
}
