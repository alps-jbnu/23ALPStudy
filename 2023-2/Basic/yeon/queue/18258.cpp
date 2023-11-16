#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    
    queue <int> q;

    while(t--){
        
        string str;
        cin >> str;
        
        if(str == "push"){
            int tmp;
            cin >> tmp;
            q.push(tmp);
        } else if(str == "pop"){
            if(q.empty()) cout << -1 << '\n'; 
            else{
                cout << q.front() << '\n';
                q.pop();
            }
        } else if(str == "front"){
            if(q.empty()) cout << -1 <<'\n';
            else cout << q.front() << '\n';
            
        } else if(str == "back"){
            if(q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
        
        else if(str == "size") cout << q.size() << '\n';
        else if (str == "empty"){
            if(q.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }  
    }
    return 0;
}
