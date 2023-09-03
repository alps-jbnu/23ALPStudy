#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int t;
	int n;
    cin >> t;
    
    for(int i=0; i<t; i++) {
        bool error = false;
        deque<int> dq;
        string order, input;
        cin >> order;
        cin >> n;
        cin >> input;
        string tmp="";
        
        if(n!=0) {
            for(int j=0; j<input.length(); j++) {
                if(input[j]=='[' || input[j]==']' || input[j]==',') {
                    if(input[j]!='[') 
						dq.push_back(stoi(tmp));  //콤마나 ]가 나오면 숫자가 나온 뒤 이므로 string to int를 이용해 int형으로 덱에 넣음  
                    tmp="";               // 다시 tmp비우기  
                    continue;
                }
                tmp += input[j];       //숫자면 tmp에 저장해놓음  
            }
        }
        
        int reverse = 1;
        for(int j=0;j<order.length();j++){
            if(order[j]=='R'){
                reverse *= -1;       //reverse가 -1이면 뒤집힌 상태  
            }
            else{
                if(dq.size()==0) {
                    cout<<"error"<<"\n";
                    error=true;
                    break;
                }
                if(reverse==1) 
					dq.pop_front();
                else 
					dq.pop_back();
            }
        }
        
        if(!error){
            cout<<"[";
            if(reverse==1){
                while(!dq.empty()){
                    if(dq.size()!=1) 
						cout<<dq.front()<<",";
                    else 
						cout<<dq.front();
						
                    dq.pop_front();
                }
            }
            else{
                while(!dq.empty()){
                    if(dq.size()!=1) 
						cout<<dq.back()<<",";      //배열이 reverse면 뒤에서부터 pop 
                    else 
						cout<<dq.back();
						
                    dq.pop_back();
                }
            }
            cout<<"]\n";
        }
    }
    return 0;
}
