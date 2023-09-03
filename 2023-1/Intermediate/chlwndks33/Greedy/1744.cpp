#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[51];
bool istied[51];
int minuscnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        if(arr[i] < 0) minuscnt++;
    }
    if(minuscnt % 2 == 1) minuscnt--;
    sort(arr,arr+n);
    int ans =0;

    for(int i=0; i<minuscnt; i++) { //음수먼저 
        if(!istied[i]) {
            istied[i] = true;
            istied[i+1] = true;
            ans += arr[i] * arr[i+1];
        }
        else continue;
    }
    for(int i=n-1; i>=minuscnt; i--) { //그다음 양수
        if(!istied[i]) {
            if(i != minuscnt && arr[i] + arr[i-1] < arr[i] * arr[i-1]) {
                istied[i] = true;
                istied[i-1] = true;
                ans += arr[i] * arr[i-1];
            }
            else {
                ans += arr[i];
            }
        }
        else {
            continue;
        }
    }
    cout << ans;
}