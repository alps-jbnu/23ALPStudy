#include <iostream>
#include <array>
using namespace std;

int main(void) 
{
    array<int, 4> arr = { 0 };

    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 4; i++)
            cin >> arr[i];

        int count = 0;
        for (int i = 0; i < 4; i++)
            if (arr[i] == 1)
                count++;
        if (count == 0)
            cout << 'D' << endl;
        else if (count == 1)
            cout << 'C' << endl;
        else if (count == 2)
            cout << 'B' << endl;
        else if (count == 3)
            cout << 'A' << endl;
        else
            cout << 'E' << endl;
    }

    return 0;
}