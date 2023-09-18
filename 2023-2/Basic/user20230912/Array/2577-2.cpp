#include <iostream>

int solution[10];

int main()
{
    long long i_a, i_b, i_c;
    std::cin >> i_a >> i_b >> i_c;

    long long d = i_a * i_b * i_c;

    while (d != 0) {
        solution[d % 10]++;
        d /= 10;
    }

    for (int i = 0; i < 10; i++) {
        std::cout << solution[i] << '\n';
    }
}
