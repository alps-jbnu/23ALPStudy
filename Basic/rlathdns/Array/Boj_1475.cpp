#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main(void){
    int arr[10] = {};
    string s;
    cin >>s;
    
    for(int i= 0; i< s.length(); i++)
            arr[s[i]-48]++;
    int k = (arr[6] + arr[9]+1)/2;//6과 9는 같이 쓸 수 있기 때문에 나누기 2 해준후 반올림(+1) 해주기.
    arr[6] = k;
    arr[9] = k;
    int max = 0;
    for(int i = 0; i<10; i++){
        if(max<arr[i]) max = arr[i];//가장 개수가 많은 수를 max를 사용해 찾은 후 출력해주기.
    }
    cout<< max;
}
