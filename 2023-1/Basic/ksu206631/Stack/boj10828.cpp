#include <iostream>
#include <string>
using namespace std;
int cnt = 0;
class stack{
private:
    int s;//   empty를 오류없이 사용하기 위해 -1로 n을 선언.
    static const int max_size = 10001;
    int save[max_size];
    int a;
    
    
    
    
public:
    stack(){s = -1;}
    ~stack(){}
    
    void push(int w){
        save[++s] = w;
        
    }
    void pop(){
        if(s ==-1) cout << "-1"<<"\n";
        else if(s>-1&&s!=-1){
            cout << save[s--]<<"\n";
        }
    }
    void size(){
        cout << s+1 << "\n";
    }
    void empty(){
        if(s==-1)
            cout << "1"<<"\n";
        else if(s>-1 && s!=-1)
            cout <<"0"<<"\n";
        
            
    }
    void top(){
        if(s!=-1){
            
            cout <<save[s]<<"\n";
            
        }
        else if(s<=-1){
            cout << "-1"<<"\n";
        }
    }
};
int main(void){
    int n;
    string od;
    int word;
    stack s;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> od;
        if(od=="push"){
            cin >> word;
            s.push(word);
            
        }
        if(od == "pop"){
            s.pop();
        }
        if(od=="size"){
            s.size();
        }
        if(od=="empty"){
            s.empty();
        }
        if(od=="top"){
            s.top();
        }

    }
    
}
