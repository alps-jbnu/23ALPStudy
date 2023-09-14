#include <iostream>
#include <string>
#include<queue>
using namespace std;
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    deque<int> dq;
    int n;
    cin >> n;
    while(n--){
        string s;
        cin>>s;
        if(s=="push_back"){
            int num;
            cin >> num;
            dq.push_back(num);
        }
        else if(s=="push_front"){
            int num;
            cin>>num;
            dq.push_front(num);
        }
        else if(s=="pop_front"){
            if(dq.empty())
                cout<<-1<<"\n";
            else{
                cout<< dq.front()<<"\n";
                dq.pop_front();
            }
        }
        else if(s=="pop_back"){
            if(dq.empty())
                cout<<-1<<"\n";
            else{
                cout<< dq.back()<<"\n";
                dq.pop_back();
            }
        }
        else if (s == "size")
              cout << dq.size() << '\n';
        else if (s == "empty")
              cout << dq.empty() << '\n';
        else if (s == "front") {
              if(dq.empty()) cout << -1 << '\n';
              else cout << dq.front() << '\n';
            }
            else { // back
              if(dq.empty()) cout << -1 << '\n';
              else cout << dq.back() << '\n';
            }
    }
}
