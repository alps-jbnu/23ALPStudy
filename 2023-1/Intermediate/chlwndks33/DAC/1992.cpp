// 

#include <iostream>
#include <string>
using namespace std;

int n;
string board[65];
string ans;

void func(int a, int b, int n) {
    if(n==1) { //base case
        ans+=board[a][b];
        return;
    }
    char start = board[a][b];
    for(int i=a; i<a+n; i++) {
        for(int j=b; j<b+n; j++) {
            if(start!=board[i][j]) {
                ans.append("(");
                func(a,b,n/2);
                func(a,b+n/2,n/2);
                func(a+n/2,b,n/2);
                func(a+n/2,b+n/2,n/2);
                ans.append(")");
                return;
            }
        }
    }
    ans+=board[a][b];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> board[i];
    }
    func(0,0,n);
    cout << ans;
}