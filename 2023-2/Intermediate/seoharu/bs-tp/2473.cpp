#include <iostream>
#include <algorithm>

long a[5001];

int main() 
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::sort(a, a + n);

    long result[3] = {a[0], a[1], a[2]};

    for (int st = 0; st < n; st++) 
    {
        int left = st + 1;
        int right = n - 1;

        while (left < right) 
        {
            long sum = a[st] + a[left] + a[right];
            long data = std::abs(result[0] + result[1] + result[2]);
            if (std::abs(sum) < data) 
            {
                // sum = data;
                result[0] = a[st];
                result[1] = a[left];
                result[2] = a[right];
            }
            if (sum > 0)
                right--;
            else
                left++;
        }
    }

    // 결과 오름차순으로 출력 <- 이미 정렬되어 있음

    for (int i = 0; i < 3; i++)
        std::cout << result[i] << " ";

}
