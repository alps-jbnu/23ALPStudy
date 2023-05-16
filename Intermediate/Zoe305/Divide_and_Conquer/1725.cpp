#include <bits/stdc++.h>
using namespace std;

int a[100000];
int n;

int subarr(int i, int j){
    if(i == j) return a[i];

    int mid = (i+j)/2;
    int res = max(subarr(i, mid), subarr(mid+1, j));

    int v = a[mid];
    int l = mid;
    int r = mid;

    while(l > i || r < j){
        int p = l>i ? a[l-1] : -1;
        int q = r<j ? a[r+1] : -1;
        if(p > q){
            v = min(v, p);
            l--;
        }else{
            v = min(v, q);
            r++;
        }
        res = max(res, v*(r-l+1));
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