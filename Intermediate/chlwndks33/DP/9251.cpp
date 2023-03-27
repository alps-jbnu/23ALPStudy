// Baekjoon - 9251번 LCS

#include <iostream>
#include <string>
using namespace std;

string c;
string s;
int d[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> s;
    for(int i=1; i<=c.size(); i++) {
        for(int j=1; j<=s.size(); j++) {
            if(c[i-1] == s[j-1]) {
                d[i][j] = d[i-1][j-1] + 1;
            }
            else {
                d[i][j] = max(d[i-1][j], d[i][j-1]);
            }
        }
    }
    cout << d[c.size()][s.size()];
    

}