#include <iostream>
#include <string>
#include<queue>
using namespace std;
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    queue<int> q;
    int n;
    string s;
    cin >> n;
    for(int i = 1; i<=n; i++){
        q.push(i);
    }
    while(q.size()>1){
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout<<q.front();
}
