#include <iostream>
#include <queue>

using namespace std;

int main(){

    int t; //명령 수
    cin >> t;
    
    queue <int> q; //queue 생성

    while(t--){
        
        string str;
        cin >> str;
        
        if(str == "push"){
            int tmp;
            cin >> tmp;
            q.push(tmp);
            
        } else if(str == "front"){
            if(q.empty() == true) cout << -1 << endl; //스택에 정수가 없는 경우
            //queue 맨 앞의 원소 리턴
            else cout << q.front() << endl;
            
        } else if(str == "back"){
            //queue 맨 뒤의 원소 리턴
            if(q.empty() == true) cout << -1 << endl; //스택에 정수가 없는 경우
            else cout << q.back() << endl;
        }
        
        else if(str == "size") cout << q.size() << endl;
        else if (str == "empty"){
            if(q.empty() == true) cout << 1 << endl; //비어 있는 경우 1 출력
            else cout << 0 << endl;
        }
        
        else if(str == "pop"){
            if(q.empty() == true) cout << -1 << endl; 
            else{ //가장 위에 있는 것을 빼므로 front 출력 후 pop 해준다.
                cout << q.front() << endl;
                q.pop();
            }
        }
        
    }
    return 0;
}
