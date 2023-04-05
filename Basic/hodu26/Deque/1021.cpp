#include <bits/stdc++.h>

using namespace std;

deque<int> deq;

int main(){
    ios::sync_with_stdio(0);cin.tie();

    int N,M,find, cnt=0, tmp=0;

    cin >> N >> M;

    for (int i=1;i<=N;i++){
        deq.push_back(i);
    }

    while (M--){
        cin >> find;

        tmp = 0;

        if (find == deq.front()){
            deq.pop_front();
            continue;
        }
        else {
            while (find != deq.front()){
                deq.push_front(deq.back());
                deq.pop_back();
                tmp++;
            }
            deq.pop_front();
        }
        if (tmp <= deq.size()+1-tmp){
            cnt += tmp;
        }
        else {
            cnt += (deq.size()+1-tmp);
        }
    }

    cout << cnt;

    return 0;
}
