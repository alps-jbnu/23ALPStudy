#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int A, B, C;
    cin >> A >> B >> C;
    string str = to_string(A * B * C);

    int arr[10] = { 0 };
    for (int i = 0; i < str.size(); i++)
    {
        arr[static_cast<int>(str[i]- 48)]++;        // O(N)으로 처리
    }

    for (int i = 0; i < 10; i++)
        cout << arr[i] << endl;
    return 0;
}