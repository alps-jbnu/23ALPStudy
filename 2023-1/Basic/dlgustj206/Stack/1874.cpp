#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int cnt = 1;
    stack<int> S;
    string ans;
    while(n--){
        int t;
        cin >> t;
        while(cnt <= t){
            S.push(cnt++);
            ans+="+\n";
        }
        if(S.top() != t){
            cout << "NO\n";
            return 0;
        }
        S.pop();
        ans+="-\n";
    }
    cout<<ans;
}