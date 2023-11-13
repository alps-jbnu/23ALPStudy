#include <iostream>
using namespace std;

int total = 0;
int summ = 0;

void f(int * arr, int size, int start, int sum)
{
    if(start == size)
    {
        
    }
    else
    {
        for(int i = start; i < size; i++)
        {
            summ += arr[i];
            if(summ == sum)
                total++;
            f(arr, size, i + 1, sum);
            summ -= arr[i];
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, s;
    cin >> n >> s;
    
    int * arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    f(arr, n, 0, s);
    cout << total << endl;
}
