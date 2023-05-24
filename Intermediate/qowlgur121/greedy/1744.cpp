/*
수 묶기
최대 이런 조건이 나와서 그리디로 접근.

오름차순으로 정렬해서 큰수끼리 곱하고 더하는 데 주의할 점은 0,1은 곱해도 값이 변하지 않으니까 묶지 않아야 함. 더해주자.

*/

#include <iostream>
#include <algorithm>

int main() {
    int n;
    int sum = 0;
    std::cin >> n;
    int arr[100005]; 
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    std::sort(arr, arr + n); 
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= -1 && arr[i + 1] <= 0 && i < n - 1) // 음수를 묶어서 처리할 수 있는 경우
        {
            sum += arr[i] * arr[i + 1];
            i++;
        }
        else if (arr[i] <= 0) // 0과 1은 묶어서 처리하지 않고 그대로 더한다. 왜냐면 곱해도 값이 달라지지 않기 때문
        {
            sum += arr[i];
        }
        else // 양수 처리
        {
            for (int j = n - 1; j >= i; j--) // 뒤에서부터 탐색한다
            {
                if (j > i && arr[j] != 1 && arr[j - 1] != 1) // 묶어서 처리할 수 있는 경우
                {
                    sum += arr[j] * arr[j - 1];
                    j--;
                }
                else // 묶을 수 없는 경우
                {
                    sum += arr[j];
                }
            }
            break;
        }
    }
    std::cout << sum;
    return 0;
}
