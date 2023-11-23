#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, l;
    cin >> n >> l;
    int * arr;
    deque<int> d;
    
    arr = new int[n];
    
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    for(int i = 0; i < l; i++)
    {
        while(1)
        {
            if(d.empty())
            {
                d.push_front(i);
                break;
            }
            else if(arr[d.front()] > arr[i])
            {
                d.pop_front();
            }
            else
            {
                d.push_front(i);
                break;
            }
        }
        cout << arr[d.back()] << ' ';
    }
    
    for(int i = 0; i < n - l; i++)
    {
        int k = i + l;
        
        if(d.back() == i)
        {
            d.pop_back();
        }
        
        while(1)
        {
            if(d.empty())
            {
                d.push_front(k);
                break;
            }
            else if(arr[d.front()] > arr[k])
            {
                d.pop_front();
            }
            else
            {
                d.push_front(k);
                break;
            }
        }
        cout << arr[d.back()] << ' ';
    }
    
    delete[] arr;
}
