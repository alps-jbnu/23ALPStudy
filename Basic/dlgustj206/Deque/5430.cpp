#include <iostream>
#include <deque>
using namespace std;

deque<int> dq;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        string p;
        int n;
        cin>>p;
        cin>>n;
        string arr;
        cin>>arr;
        string tmp="";

        for(int i=0; i<arr.length(); i++){
            if(arr[i]==','||arr[i]=='['||arr[i]==']'){
                if(tmp=="")
                    continue;
                dq.push_back(stoi(tmp));
                tmp="";
                continue;
            }
            tmp+=arr[i];
        }

        bool head=true; //뒤집히지 않은 상태: true, 뒤집힌 상태: false
        bool error=false;
        for(int j=0; j<p.length(); j++){
            if(p[j]=='R'){
                head=!head;
            }
            else if(p[j]=='D'){
                if(dq.empty()){
                    error=true;
                    break;
                }
                if(head) dq.pop_front();
                else dq.pop_back();
            }
        }

        if(error){
            cout<<"error\n";
        }
        else{
            cout<<"[";
            while(!dq.empty()){
                if(head){
                    cout<<dq.front();
                    if(dq.size()>1)
                        cout<<", ";
                    dq.pop_front();
                }
                else{
                    cout<<dq.back();
                    if(dq.size()>1)
                        cout<<", ";
                    dq.pop_back();
                }
            }
            cout<<"]\n";
        }
    }
}