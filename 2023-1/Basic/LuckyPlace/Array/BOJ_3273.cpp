#include <iostream>
using namespace std;
   
// main안에 이 배열들을 선언하면 stack overflow난다. 전역변수로 heap에 저장해야 overflow가 나지 않는다.
int arr[1000005] = {};            // 원래 수열
 bool arr_num[2000005];              // 입력된 수를 저장하는 bool타입 배열
//int arr_num[2000005] = { 0 };       // int로 해보려 했는데 너무 크다


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int result = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int sum;
    cin >> sum;

    for (int i = 0; i < N; i++)
    {
        if (sum-arr[i] > 0 && arr_num[sum-arr[i]])
            result++;
        arr_num[arr[i]] = true;
    }
    //for (int i = 0; i < N; i++)
    //{
    //    for (int j = i+1; j < N; j++)       // O(N^2)으로 풀긴 했지만 O(N)으로 풀어야 정답 인정인듯
    //    {
    //        if ((arr[i] + arr[j]) == sum)
    //            result++;
    //    }
    //}
    cout << result << endl;
    return 0;
}