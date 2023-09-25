#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        string p;
        cin >> p;

        int n;
        cin >> n;

        string str;
        cin >> str;

        deque <int> dq;
        string tmp = "";

        for(int i=0; i<str.length(); i++){
            if(str[i] == '[') continue;
            else if(str[i] >= '0' && str[i] <= '9') tmp += str[i];
            else if(str[i] == ',' || str[i] == ']'){
                if(!tmp.empty()){
                    dq.push_back(stoi(tmp));
                    tmp.clear();
                }
            }
        }

        bool rev = true; //true 정방향, 역은 false
        bool isEmpty = false;

        for(int j=0; j<p.size(); j++){
            if(p[j] == 'R'){
                rev = !rev; //방향 전환
            } else{
                n--;
                if(!dq.empty()){
                    if(rev) dq.pop_front();
                    else dq.pop_back();
                } else{
                    isEmpty = true;
                    cout << "error" << '\n';
                    break;
                }
            }
        }

        if(!isEmpty){
            cout << "[";
            if(rev){
                while(!dq.empty()){
                    cout << dq.front();
                    dq.pop_front();
                    if(!dq.empty()) cout << ",";
                }
            } else{
                while(!dq.empty()){
                    cout << dq.back();
                    dq.pop_back();
                    if(!dq.empty()) cout << ",";
                }
            }
        cout << "]" << '\n';
        }
    }
    return 0;
}
