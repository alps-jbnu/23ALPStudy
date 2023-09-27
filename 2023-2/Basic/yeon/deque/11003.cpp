#include <iostream>
#include <deque>

using namespace std;

deque <pair<int, int>> dq;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, l;
    cin >> n >> l;

    for(int i=0; i<n; i++){

        int tmp;
        cin >> tmp;

        while(!dq.empty() && dq.back().second >= tmp){
            dq.pop_back();
        } //dq 안에 들어있는 원소보다 tmp값이 클 경우 pop_back

        dq.push_back({i, tmp}); //새로운 숫자 삽입

        if(dq.front().first <= i-l){ //주어진 구간을 벗어나는 숫자들 제거 ((1, {2,3}
            dq.pop_front();
        }

        cout << dq.front().second << ' ';
    }
    return 0;
}
