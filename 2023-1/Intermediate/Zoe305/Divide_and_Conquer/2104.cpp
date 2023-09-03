#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a[100000];
int n;

ll subarr(int i, int j){
    if(i == j) return a[i]*a[i];

    int mid = (i+j)/2;
    ll res = max(subarr(i, mid), subarr(mid+1, j));

    ll v = a[mid];
    ll min = a[mid];
    ll l = mid;
    ll r = mid;

    while(l > i || r < j){
        ll p = l>i ? a[l-1] : -1;
        ll q = r<j ? a[r+1] : -1;
        if(p >= q){
            v += p;
            if(min > p && p != -1) min = p;
            l--;
        }else{
            v += q;
            if(min > q && q != -1) min = q;
            r++;
        }
        res = max(res, v*min);
    }
    return res;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    cout << subarr(0, n-1);
}