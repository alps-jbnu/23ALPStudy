#include <iostream>
#include <queue>
#include <algorithm> //find

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    deque <int> dq;

    int n, m; //큐의 크기와 뽑아내려고 하는 개수
    cin >> n >> m;

    //위치가 순서대로 주어짐
    for(int i=1; i<=n; i++){
        dq.push_back(i);
    }

    int res = 0;

    while(m--){
        int k;
        cin >> k;

        int idx = find(dq.begin(), dq.end(), k) - dq.begin(); //t의 위치

        while(dq.front() != k){
            //연산의 최솟값
            if(idx < dq.size() - idx){
                //idx가 dq.size()보다 컸다면 overflow가 발생할 수 있음
                //dq.size()는 unsigned int -> (int)dq.size()로 사용하는 것도 좋음
                
                dq.push_back(dq.front()); //왼쪽으로 한 칸 이동
                dq.pop_front();
            } else{
                dq.push_front(dq.back()); //오른쪽으로 한 칸 이동
                dq.pop_back();
            }
            res++;
        }
        dq.pop_front(); //첫번째 원소 뽑아내기
    }

    cout << res << '\n';

    return 0;
}
