#include <bits/stdc++.h>
#define pii pair<int, int>
const int MAX = 200 + 1;
using namespace std;

int result = 0;
int arr[10];
vector<int> vec;

void Solve(int* temp, int solved, int q)
{
    if(q == 10)
    {
        if(solved >= 5) result++; 
    }
    else
    {
        int chamx3 = 0;
        if(q >= 2)
        {
            if(temp[q - 1] == temp[q - 2]) chamx3 = temp[q - 1];
        }
        
        for(int i = 1; i <= 5; i++)
        {
            if(chamx3 == i) continue;
            
            temp[q] = i;
            if(vec[q] == i) Solve(temp, solved + 1, q + 1);
            else Solve(temp, solved, q + 1);
            
            temp[q] = 0;
        }
    }
}

int main()
{
    for(int i = 0; i < 10; i++)
    {
        cin >> arr[i];
        vec.push_back(arr[i]);
    }
    
    Solve(arr, 0, 0);
    
    cout << result;
    
    return 0;
}