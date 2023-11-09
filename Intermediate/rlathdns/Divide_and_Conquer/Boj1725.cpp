#include <iostream>
#include <algorithm>
#include<stack>
using namespace std;
int n,ans,arr[1000001];
stack<int> s;
int main(void){
    cin >> n;
    for(int i =1; i<=n;i++) cin >> arr[i];
    s.push(0);
    for(int i =1; i<=n+1; i++){
        while(!s.empty()&&arr[s.top()]>arr[i]){
            int check = s.top();
            s.pop();
            ans = max(ans,arr[check]*(i-s.top()-1));
        }
        s.push(i);
    }
    cout << ans;
}
