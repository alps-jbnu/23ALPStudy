#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, sum=0;
    cin>>k;
    stack<int> s;
    while(k--){
        int t;
        cin>>t;
        if(t==0) s.pop();
        else s.push(t);
    }
    int size=s.size();
    for(int i=0; i<size; i++){
        sum+=s.top();
        s.pop();
    }
    cout<<sum;
}