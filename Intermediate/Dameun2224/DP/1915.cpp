#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <string.h>
#include <string>
using namespace std;

int a[1005][1005];
int d[1005][1005]; 
string s;
/*
*   1 2
*   3 4
*   일때, 1 -> 2 -> 3 -> 4 순으로 진행
*   위왼이 1이면서 위왼의 d값이 같다면,
*   d[i][j] = d[i-1][j-1] + 1
*   자신의 왼쪽 대각선 + 1
*/
int n, m;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= m; j++)
            a[i][j] = s[j - 1] - '0';
    }
        
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++) {
            if (a[i][j]) {
                if (a[i - 1][j] && a[i][j - 1]) {   // 위와 왼이 1이면
                    if (d[i - 1][j] == d[i][j - 1]) {
                        if (d[i - 1][j - 1] == d[i - 1][j]) d[i][j] = d[i - 1][j - 1] + 1;
                        else d[i][j] = min(d[i - 1][j - 1], d[i - 1][j]) + 1;
                    }
                    else d[i][j] = min(d[i - 1][j], d[i][j - 1]) + 1;
                }
                else d[i][j] = 1;   // 위왼중 하나라도 0이면 d[i][j] = 1
            }
            ans = max(ans, d[i][j]);
        }
    }
    
    cout << ans * ans << '\n';


    return 0;
}
