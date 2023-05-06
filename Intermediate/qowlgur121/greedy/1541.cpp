//[백준] 1541번: 잃어버린 괄호

/*
이 문제는 최소를 구해야 한다. 최소 같은 건 그리디로 접근해보자.

각 단계에서 최대한 많은 값을 뺄 수 있는 방법을 선택해야 한다. 
그래서 뺄셈 기호가 나오면 이후에 등장하는 모든 수를 빼주는 것이 최선이다.

예를 들어, "55-50+40"의 경우, 최초로 “-” 기호가 나오면 이후에 등장하는 모든 수를 빼주어야 한다. 
즉, “-50”과 “+40”을 더하는 대신, “-(50+40)”을 계산하는 것이 최선이다.

*/

#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int sum = 0;
    int tmp = 0;
    bool flag = false; // '-'가 등장했는지 체크

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+' || s[i] == '-') {
            if (flag) { // '-'등장 이후로 모든 값 음수화
                sum -= tmp;
                tmp = 0;
            }
            else { // '-'등장 이전 모든 값 양수화
                sum += tmp;
                tmp = 0;
            }

            if (s[i] == '-') flag = true; // '-'등장 시 체크
        }
        else { // tmp변수에 값 누적
            tmp *= 10;
            tmp += s[i] - '0'; // char 데이터를 정수로 변환
        }
    }

    // 마지막 숫자 처리. 마지막 값이 tmp에 들어갔고 sum에 처리가 안 되었기 때문.
    if (flag) sum -= tmp;
    else sum += tmp;

    std::cout << sum << std::endl;

    return 0;
}
