#include <iostream>
#include <algorithm>
using namespace std;

int arr[500001];
int n,m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr,arr+n);
    cin >> m;
    while(m--) {
        int a;
        cin >> a;
        cout << upper_bound(arr,arr+n, a) - lower_bound(arr,arr+n, a) << " ";
    }
}

// int arr[20000002];  //단순 정렬 사용
// int n,m;

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n;
//     for(int i=0; i<n; i++) {
//         int a;
//         cin >> a;
//         arr[a+10000000]++;
//     }
//     cin >> m;
//     for(int i=0; i<m; i++) {
//         int a;
//         cin >> a;
//         cout << arr[a+10000000] <<" ";
//     }


// }
