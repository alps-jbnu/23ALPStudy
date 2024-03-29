#include<iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;

/*
* 1, 3, 5개인 경우 상근이가 이긴다.
* 2, 4, 6개인 경우 창영이가 이긴다.
* 7개인 경우 상근이는 1, 3개를 가져갈 수 있다.
* 1개를 가져간 경우 남는건 6, 창영이가 1, 3중 가져가면 남는건 5, 3
* 3개를 가져간 경우 남는건 4, 창영이가 1, 3중 가져가면 남는건 3, 1
* 8개인 경우 .. 남는건 6, 4, 4, 2
* 홀수 + 홀수 = 짝수 (본인이 가져간 돌 + 상대가 가져간 돌)
* 홀수 - 짝수 = 홀수, 짝수 - 짝수 = 짝수 (본인턴이 홀수인 경우 다시 홀수로, 짝수인 경우 짝수로)
* 가져갈 수 있는 돌의 개수는 항상 홀수이고, 다시 자기턴이 되면 처음에서 짝수개만큼 돌이 없어진다.
* 따라서 홀수인 경우 상근이가 이기고, 짝수인 경우 창영이가 이긴다.
*/

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    if (n % 2 == 0) cout << "CY";
    else cout << "SK";

    return 0;
}
