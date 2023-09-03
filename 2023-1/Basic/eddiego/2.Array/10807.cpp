#include <bits/stdc++.h>

using namespace std;

int a[105]={};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,x;
    int cnt = 0;

    cin >> n;
    for(int i = 0; i<n;i++)
        cin >> a[i];
    cin >> x;
    for(int i = 0; i < n;i++)
        if(a[i]==x)
            cnt++;
    cout << cnt;
}