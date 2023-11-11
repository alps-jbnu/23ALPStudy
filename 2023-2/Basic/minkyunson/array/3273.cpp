#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    bool * p = (bool *) calloc(1000000, sizeof(bool));
    int n, x;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        p[x - 1] = 1;
    }
    
    cin >> x;
    
    if(x < 3 || x == 2000000)
        cout << "0" << endl;
    else if(x < 1000002)
    {
        int t = 0;
        for(int i = 0; i < (x - 1) / 2; i++)
        {
            if(p[i] && p[x - 2 - i])
            {
                t++;
            }
        }
        cout << t << endl;
    }
    else if(x < 2000000)
    {
        int t = 0;
        for(int i = 999999; i > (x - 2) / 2; i--)
        {
            if(p[i] && p[x - 2 - i])
            {
                t++;
            }
        }
        cout << t << endl;
    }
    
    free(p);
}
