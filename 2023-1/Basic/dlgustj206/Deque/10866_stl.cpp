#include <iostream>
#include <deque>
using namespace std;

deque<int> dq;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        if(s=="push_front"){
            int x;
            cin>>x;
            dq.push_front(x);
        }
        else if(s=="push_back"){
            int x;
            cin>>x;
            dq.push_back(x);
        }
        else if(s=="pop_front"){
            if(dq.empty()) cout<<-1<<"\n";
            else{
                cout<<dq.front()<<"\n";
                dq.pop_front();
            }
        }
        else if(s=="pop_back"){
            if(dq.empty()) cout<<-1<<"\n";
            else{
                cout<<dq.back()<<"\n";
                dq.pop_back();
            }
        }
        else if(s=="size") cout<<dq.size()<<"\n";
        else if(s=="empty"){
            if(dq.empty()) cout<<1<<"\n";
            else cout<<0<<"\n";
        }
        else if(s=="front"){
            if(dq.empty()) cout<<-1<<"\n";
            else cout<<dq.front()<<"\n";
        }
        else if(s=="back"){
            if(dq.empty()) cout<<-1<<"\n";
            else cout<<dq.back()<<"\n";
        }
    }
}