#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    int arr[10] = {};

    //자릿수 별로 계산
    while(n>0){
        arr[n%10]++;
        n/=10;
    }

    int sum = arr[6]+arr[9]; //6과 9는 바꾸어 쓸 수 있으므로 /2 해줄 것

    arr[6] = sum/2;
    arr[9] = sum - arr[6];

    //인덱스의 최댓값이 곳 필요한 세트의 개수
    int max = -1;

    for(int i=0; i<10; i++){
        if(max<arr[i]) max = arr[i];
    }

    cout << max << '\n';

    return 0;
}
