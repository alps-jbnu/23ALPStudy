#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main(void){
    int n;
    int comp;
    int stack_in = 1;
    string r;
    stack<int> S;
    cin >>n;
    for(int i = 1; i<=n;i++){
        cin >> comp;
        if(comp >= stack_in)//입력된 수열의 값이 스택에 들어오는 값보다 크거나 같으면 해당 값을 스택에 넣어주기
        {
            while(comp+1!=stack_in){
                S.push(stack_in++);
                r += "+\n";
            }
            S.pop();//수열을 만들기 위해 스택에 만들어진 수열 빼주기
            r+="-\n";
        }
        else{
            if(S.top() == comp){
                S.pop();//입력된 수열의 값과 스택의 가장 최상위 값이 같을 경우 pop해주기
                r += "-\n";
                
            }
            else{
                r ="NO";//위 조건 어디에도 속하지 않을 경우 NO를 출력하고 프로그램 멈추기
                break;
            }
        }
       
    }
    cout <<r;
    
}
