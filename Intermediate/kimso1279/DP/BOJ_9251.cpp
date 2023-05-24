#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
  	cin.tie(0);

    string a,b;
    int dp[1001][1001];

    cin >> a >> b;    
    
    for(int i=1; i<=a.length(); i++){
        for(int j=1; j<=b.length(); j++){
            // 점화식
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1; // 대각선 값 + 1
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // 왼쪽, 위 중 큰 값 선택 
            }
        }
    }
    cout << dp[a.length()][b.length()] << "\n";
}
