#include <iostream>
#include <queue>

std::queue<std::pair< int, int >> q;

int count;

void hanoi(int n, int from, int temp, int to);

int main()
{
    int input;

    std::cin >> input;

    hanoi(input, 1, 2, 3);

    std::cout << count << '\n';
    while (!q.empty()) {
        std::cout << q.front().first << ' ' << q.front().second << '\n';
        q.pop();
    }

}

void hanoi(int n, int from, int temp, int to) {

    if (n == 1) {
        q.push({ from, to });
        count++;
    }
    else {
        hanoi(n - 1, from, to, temp);
        q.push({ from,to }); count++;
        hanoi(n - 1, temp, from, to);
    }

}
