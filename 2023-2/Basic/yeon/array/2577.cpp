#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    int arr[10] = {};
    cin >> a >> b >> c;

    int sum = a*b*c;

    //계산 결과를 자릿수별로 확인
    while(sum>0){
        arr[sum%10]++;
        sum/=10;
    }

    for(int i=0; i<10; i++){
        cout << arr[i] << '\n';
    }
    
    return 0;

}
