#include <iostream>
using namespace std;

int arr[101];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, v, count=0;
    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];
    cin>>v;
    for(int i=0; i<n; i++)
        if(arr[i]==v) count++;
    cout<<count;
}