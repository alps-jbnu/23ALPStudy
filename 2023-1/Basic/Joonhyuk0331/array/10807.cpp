#include <iostream>
using namespace std;
int n=0,f=0, aaa[100],sss;
int main() 
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> aaa[i];
    }
    cin >> f;
    for (int i = 0; i < n; i++)
    {
        if (f == aaa[i])
            sss++;
    }
    cout << sss << '\n';
}
