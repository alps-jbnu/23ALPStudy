#include <bits/stdc++.h>
const int MAX = 150 + 1;
using namespace std;

int N, K, result = 0;
int arr[MAX], Visited[MAX];

int main()
{
    cin >> N >> K;
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    
    int temp = arr[0];
    while(!Visited[temp])
    {
        result++;
        Visited[temp] = true;

        if(temp == K) 
        {
            cout << result;
            return 0;
        }
        temp = arr[temp];
    }
    cout << -1;

    return 0;
}