#include <iostream>
#include <stdlib.h>
using namespace std;

class dll {
public:
    int value;
    dll * before;
    dll * after;
    void init(int v, dll * b, dll * a)
    {
        value = v;
        before = b;
        after = a;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    
    dll * lla = new dll[n] {};
    
    lla[0].init(1, lla + n - 1, lla + 1);
    for(int i = 1; i < n - 1; i++)
    {
        lla[i].init(i + 1, lla + i - 1, lla + i + 1);
    }
    lla[n - 1].init(n, lla + n - 2, lla + 0);
    
    int * result = new int[n] {};
    
    dll * address = lla + k - 1;
    for(int i = 0; i < n; i++)
    {
        result[i] = address -> value;
        address -> before -> after = address -> after;
        address -> after -> before = address -> before;
        for (int j = 0; j < k; j++)
        {
            address = address -> after;
        }
    }
    
    cout << "<";
    for(int i = 0; i < n - 1; i++)
    {
        cout << result[i] << ", ";
    }
    cout << result[n - 1] << ">";
}
