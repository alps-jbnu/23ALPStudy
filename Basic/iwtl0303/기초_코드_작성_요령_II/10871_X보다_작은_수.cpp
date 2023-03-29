#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x;
    cin >> n  >> x;
    int arr[10005];
    for(int i=0; i<n; i++){
       cin >> arr[i];
       if (arr[i] < x) cout << arr[i] << " ";
    }
    return 0;
}
