#include <iostream>
using namespace std;

long long f(int a, int b, int c)
{
    if(b == 1)
        return a % c;
    else if(b % 2)
    {
        long long k = f(a, b / 2, c);
        return k * k  % c * a % c;
    }
    else
    {
        long long k = f(a, b / 2, c);
        return k * k % c;
    }
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    
    cout << f(a, b, c);
}
