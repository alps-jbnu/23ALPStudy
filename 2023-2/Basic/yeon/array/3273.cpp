#include <iostream>
using namespace std;

int arr[100001] = {};
bool sol[2000001];

int n, x;

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i]; //배열 입력
    }

    cin >> x;

    int cnt = 0;

    for(int i=0; i<n; i++){
        //존재 확인
        if(x-arr[i]>0 && sol[x-arr[i]]) cnt++; //쌍을 찾을 경우
        sol[arr[i]] = true; //방문하지 않은 경우
    }

    cout << cnt << '\n';

    return 0;
}
