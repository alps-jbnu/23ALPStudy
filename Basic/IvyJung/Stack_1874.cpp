#include <stack>
#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> s;
    
    int n;
    cin >> n;
    int pos = 1;
    string ans;
    
    while (n--){
        int t;
        cin >> t;
        while (pos <= t){
            s.push(pos++);
            ans += "+\n";
        }
        if(s.top() != t){
            cout << "NO\n";
        }
        s.pop();
        ans += "-\n";
    }
    cout << ans;
}