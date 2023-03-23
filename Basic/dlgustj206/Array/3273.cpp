#include <iostream>
using namespace std;

int occur[2000001];
int arr[100001];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, count=0;
    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];
    cin>>x;
    for(int i=0; i<n; i++){
        if(occur[x-arr[i]]==1) count++;
        else occur[arr[i]]=1;
    }
    cout<<count;
}