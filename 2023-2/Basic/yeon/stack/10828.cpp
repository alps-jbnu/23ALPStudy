#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int t;
    cin >> t;
    
    stack <int> s;
    
    while(t--){
        
        string str;
        cin >> str;
        
        if(str == "push"){
            int tmp;
            cin >> tmp;
            s.push(tmp);
            
        } else if(str == "pop"){
            if(s.empty()) cout << -1 << '\n';
            else{
                cout << s.top() << '\n';
                s.pop();
            }
            
        } else if(str == "size"){
            cout << s.size() << '\n';
            
        } else if(str == "empty"){
            if(s.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
            
        } else if(str == "top"){
            if(s.empty()) cout << -1 << '\n';
            else cout << s.top() << '\n';
            
        }
    }

    return 0;
}
