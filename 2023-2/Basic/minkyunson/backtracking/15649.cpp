#include <iostream>
using namespace std;

int k;
int * kk;

void f(int n, int m, int * arr, bool * visit)
{
    if(m == 0)
    {
        for(int i = 0; i < k; i++)
            cout << kk[i] << ' ';
        cout << '\n';
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(visit[i] == true)
            {
                continue;
            }
            else
            {
                *arr = i + 1;
                visit[i] = true;
                f(n, m - 1, arr + 1, visit);
                visit[i] = false;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    k = m;
    
    int *arr = new int[m];
    bool *visit = new bool[m];
    
    kk = arr;
    
    f(n, m, arr, visit);
    
    delete [] arr;
    delete [] visit;
}
