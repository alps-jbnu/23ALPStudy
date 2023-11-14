#include <iostream>
using namespace std;

int f(int n, int r, int c)
{
    int t = (1 << (n - 1));
    if(n == 0)
    {
        return 0;
    }
    else if(r >= (1 << (n - 1)))
    {
        if(c >= (1 << (n - 1)))
        {
            return t * t * 3 + f(n - 1, r - t, c - t);
        }
        else
        {
            return t * t * 2 + f(n - 1, r - t, c);
        }
    }
    else
    {
        if(c >= (1 << (n - 1)))
        {
            return t * t + f(n - 1, r, c - t);
        }
        else
        {
            return f(n - 1, r, c);
        }
    }
}

int main()
{
    int n, r, c;
    cin >> n >> r >> c;
    
    int t = f(n, r, c);
    cout << t << endl;
}
