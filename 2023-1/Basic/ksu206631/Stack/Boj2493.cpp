#include <iostream>
#include <string>
#include<algorithm>
#include <list>
#include <stack>
#include <utility>
using namespace std;
#define X first
#define Y second

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<pair<int,int>> s;
    int n;
    

    cin >> n;
    s.push({100000001, 0});
    for(int i = 1; i<=n; i++){
        int h;
        cin>>h;
        while(s.top().X<h)
            s.pop();
        cout << s.top().Y<<" ";
        s.push({h,i});
    }
    
    
    
}

