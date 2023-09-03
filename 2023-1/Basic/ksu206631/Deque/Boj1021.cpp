#include <iostream>
#include <string>
#include<queue>
#include<deque>
using namespace std;
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    deque<int> dq;
    int arr[51];
    int n;
    int m;
    int cnt = 0;
    cin >> n >>m;
    
    for(int i = 1; i<=n; i++){
        dq.push_back(i);
    }
    for(int i =0; i<m; i++){
        int num;
        cin >>num;
        int ind =0;
        for(int i = 0; i<dq.size(); i++){
            if(dq[i]==num){
                ind = i;
                break;
            }
        }
        if(ind<dq.size()/2+1){//덱을 기준으로 중간보다 인덱스가 앞에 있다면.
            while(1){
                if(dq.front()==num){
                    dq.pop_front();
                    break;
                }
                dq.push_back(dq.front());//앞에 있는 숫자를 뒤로 보재고
                dq.pop_front();//앞에 있던 수의 다음수를 pop해줌.
                ++cnt;
            }
        }
        else{//덱의 중간을 기준으로 인덱스 값이 뒤에 있다면
            while(1){
                if(dq.front()==num)
                {
                    dq.pop_front();
                    break;
                }
                dq.push_front(dq.back());//뒤에 있는 숫자를 앞으로 보재고
                dq.pop_back();//뒤에 있던 수의 다음수를 pop해줌.
                ++cnt;
            }
        }
                
    }
    cout << cnt;
}
