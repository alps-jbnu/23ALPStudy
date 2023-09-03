#include <bits/stdc++.h>
#include<iostream>
#include <stack>
using namespace std;
int main(void){
    stack <int> s;
    int k;
    int sum = 0;
    int n;
    cin >> k;
    
    for (int i = 0; i < k; i++){
        cin >> n;
        if(n != 0){//n이 0이 아닐경우 해당 수를 스택에 넣어주기
            s.push(n);
        }
        else{//n이 0일 경우 이전의 수를 제거하기
            s.pop();
        }
    }
    for(int i = 0; !s.empty(); i++){
        sum += s.top();//가장 위에 있는 스택의 수를 차근차근 더한 값을 sum 변수에 저장하기
        s.pop();//for문이 종료 될 수 있게 스택이 empty가 될 때 까지 하나씩 증가 시켜가면 더한 값을 스택에서 빼주기
    }
    cout << sum;
}
