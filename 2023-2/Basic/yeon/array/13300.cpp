#include <iostream>

using namespace std;

int arr[2][7] = {}; //성별, 학년별 학생수 저장 (0,1 // 1<= y <= 6)

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    while(n--){
        int s, y; //성별(여자 0, 남자 1), 학년
        cin >> s >> y;
        arr[s][y]++;
    }

    int cnt = 0;

    //필요한 방의 개수
    for(int i=0; i<2; i++){
        for(int j=0; j<7; j++){
            cnt += arr[i][j]/k;
            if(arr[i][j]%k) cnt++; //학생이 남을 경우
        }
    }

    cout << cnt;

    return 0;
}
