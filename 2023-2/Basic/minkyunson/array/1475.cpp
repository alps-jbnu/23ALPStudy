#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    int arr[10] = {};
    
    if(a == 0)
    {
        cout << "1" << endl;
        return 0;
    }
    else
    {
        while(a)
        {
            arr[a % 10] += 1;
            a = a / 10;
        }
        arr[6] = (arr[6] + arr[9] + 1) / 2;
        int max = 0;
        for(int i = 0; i < 9; i++)
        {
            if(max < arr[i])
            {
                max = arr[i];
            }
        }
        cout << max << endl;
    }
}
