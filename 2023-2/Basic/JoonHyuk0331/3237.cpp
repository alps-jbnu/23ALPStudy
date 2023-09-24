#include <iostream>
using namespace std;
int input_arr[100001];
bool arr[2000001] = {};
//투 포인터x,정렬x

int func2(int input_arr[], int n, int sum) {//(수열,수열의 길이,합)
    //a,b두 수의 합에서 a가 정해졌다면 다른것을 찾을 필요 없이 b만 찾으면 된다
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (sum - input_arr[i] < 0) continue;//outofbound방지
        if (arr[sum - input_arr[i]] == true)//arr에서 현재 찾는 수(sum-a=b에서 b) 가 있으면(true) result
            result++;
        arr[input_arr[i]] = true;//수열의 숫자를 하나씩 arr에 등록, 등록됐다면 그 숫자 번째 인덱스의 값을 true로
    }
    return result;
}

int main(void)
{
    int n = 0, sum = 0;
    cin >> n;
    for (int j = 0; j < n; j++)
        cin >> input_arr[j];//입력받은 수열
    cin >> sum;
    cout << func2(input_arr, n, sum);
}
