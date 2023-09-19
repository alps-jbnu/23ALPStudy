#include <iostream>
using namespace std;

int main()
{
    int a, b, c, t;
    cin >> a >> b >> c;
    
    t = a * b * c;
    int arr[10] = {};
    
    while(t)
    {
        arr[t % 10] += 1;
        t = t / 10;
    }
    
    for(int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }
}
