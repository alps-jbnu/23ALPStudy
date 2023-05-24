#include <iostream>

int list[10000005];

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        for (int j = 0; j < n; j++) {
            std::cin >> list[j];
        }

        int max = 0;
	      long long int profit = 0;
        for (int i = n - 1; i >= 0; --i) {  //뒤부터 돌면서 max는 마지막 날의 이익부터 시작해서 더 큰 이익을 저장해나가면서 갱신. 앞에서부터 돌면 각각의 날에 대해 최대 이익을 구해야 한다.
            if (list[i] > max)
                max = list[i];
            else
                profit += max - list[i];
        }
        std::cout << profit << std::endl;
    }
}
