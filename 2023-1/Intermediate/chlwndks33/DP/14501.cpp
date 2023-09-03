// Baekjoon - 14501번 퇴사

#include <iostream>
#include <algorithm>
using namespace std;

long long d[16];
int t[16];
int p[16];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> t[i] >> p[i];
    }
    for(int i=n; i>=1; i--) {
        int deadline = i + t[i];
        if(deadline > n+1) d[i] = d[i+1];
        else {
            d[i] = max(d[i+1], d[deadline]+ p[i]);
        } 
    }
    cout << *max_element(d+1,d+n+1);

}