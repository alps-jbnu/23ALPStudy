#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;


int main(void){
    string st, strn;
    int num;
    
    int n;
    cin >> n;
    while(n--){
        
        cin>>st;
        cin >>num;
        cin>>strn;//[1,2,3,4] 형식을 입력받을 string 문자열
        deque<int> d;
        bool flag = true;//error
        bool dir = true;//정방향과 역방향 표시
        string temp = "";
        
        for(int i = 1; i<strn.size(); i++){
            if(strn[i] == ','||strn[i]==']'){
                if(temp!=""){
                    d.push_back(stoi(temp));//stio는 string을 int형으로 바꿀 때 사용하는 함수임
                    temp = "";
                }
            }
            else{
                temp+= strn[i];
            }
        }
        
        for(int j = 0; j<st.size(); j++){
            if(st[j] == 'R'){
                dir = !dir;//R이면 정방향을 역방향으로 바꿔주기(true를 false로)
        
            }
            else if(st[j] == 'D'){
                if(d.empty()){
                    flag = false;//덱이 비어있으면 error문구 출력을 위해 true를 false로 바꿔주기
                    break;
                }
                else{
                    if(dir) d.pop_front();
                    else d.pop_back();
                }
            }
        }
        if(!flag) cout << "error\n";
        else{
            if(!dir) reverse(d.begin(),d.end());
            cout << "[";
            for(int i= 0; i<d.size(); i++){
                if(i==d.size()-1)//덱에 남은 수가 하나일 경우를 출력해주기 위한 조건문
                    cout << d[i];
                else
                    cout << d[i] <<",";
            }
            cout<<"]\n";
        }
    }
    
}
