#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[]) {

    /*
      0으로 초기화를 해야한다.
      아니면 garbage value, 즉 쓰레기 값이 들어있게 된다.
      이 때 0으로 초기화 하는 방법은 {} 괄호만 쳐주거나,
      {0,}, {0} 방식이 있다.
     */
    int count[10] = {};
    int a, b, c;

    cin >> a >> b >> c;

    int res = a * b * c;
    /*
     std::to_string(val)
     숫자(int, long, float, double 등)를 문자열(string)으로
     변환하여 반환해주는 함수를 사용한다.
     */
    string s = to_string(res);

    /*
     숫자 0은 문자로는 아스키 값 48에 해당하므로,
     인덱스 숫자 0을 얻기 위해서는 48을 빼주어야 한다.
     마찬가지로 문자 '1'을 숫자 1로 얻고자 한다면 48을 빼주어야 49 - 48 = 1로
     숫자 1을 얻을 수 있다.
     아스키 값이 기억이 안난다면, '0' 이렇게 문자로 빼주어도 된다.
    */
    for (char ch: s) {        // 문자열의 문자들을 하나씩 꺼내온다. (foreach문 활용)
        // 문자를 숫자로 변환한 값의 인덱스를 1 증가시킨다.
        count[ch - '0']++;
    }

    // 0 부터 9까지 count 배열을 출력한다. (foreach문 사용)
    for (int v: count) {
        cout << v << "\n";
    }
    return 0;
}
