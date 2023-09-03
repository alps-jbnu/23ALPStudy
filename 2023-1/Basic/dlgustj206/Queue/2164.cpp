#include <iostream>
#include <queue>
using namespace std;

queue<int> Q;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int i=1;
    cin>>n;
    
    while(n--){
        Q.push(i++);
    }

    while(Q.size()>2){
        Q.pop();
        Q.push(Q.front());
    }
    cout<<Q.back();
}