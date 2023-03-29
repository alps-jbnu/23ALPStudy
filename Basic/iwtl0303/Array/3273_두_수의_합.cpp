#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,x,cnt=0;
    int a[1000001]={0, };
    int occur[2000001] = {0, };
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>x;
    for(int i=0;i<n;i++){
        if(occur[x-a[i]]==1 && x-a[i] > 0 ) cnt++;
        occur[a[i]]=1;
    }
    cout<<cnt;
    return 0;
}
