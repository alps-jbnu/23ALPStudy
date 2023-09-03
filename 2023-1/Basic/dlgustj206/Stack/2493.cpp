#include <iostream>
#include <stack>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    stack<pair<int, int>> s;  //index, height
    int num, height;
    cin >> num;
 
    for (int i=0; i<num; i++){
        cin>>height;
        while(!s.empty()){
            if (height<s.top().second){
                cout<<s.top().first<<" ";
                break;
            }
            s.pop();
        }
        if(s.empty()){
            cout<<0<<" ";
        }
        s.push(make_pair(i + 1, height));
    }
}
