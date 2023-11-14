#include <iostream>
using namespace std;

void f(int start, int end, int n)
{
    if(n == 1)
    {
        cout << start << ' ' << end << '\n';
    }
    else
    {
        f(start, 6 - start - end, n - 1);
        cout << start << ' ' << end << '\n';
        f(6 - start - end, end, n - 1);
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    cout << (1 << n) - 1 << '\n';
    f(1, 3, n);
}
