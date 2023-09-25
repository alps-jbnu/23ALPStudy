#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int t;
    cin >> t;
    
    stack <int> s;
    
    for(int i=0; i<t; i++){
        int tmp;
        cin >> tmp;
        
        if(tmp == 0){
            s.pop();
        }
        else s.push(tmp);
    }
    
    int sum = 0;
    
    while(!s.empty()){
        sum += s.top();
        s.pop();
    }
    
    cout << sum << '\n';
    

    return 0;
}
