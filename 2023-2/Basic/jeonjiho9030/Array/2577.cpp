#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num[10] = { 0 };		//0부터 9까지 등장 횟수
    int a, b, c;
    cin >> a >> b >> c;
    int mul = a * b * c;		//곱한 값 mul에 저장
    do {				//한자릿수가 될때까지 반복
        int tmp = mul % 10;		//mul을 10으로 나눈 값(1의 자리 수)를 tmp에 저장
        mul /= 10;			//mul을 10으로 나눈 몫을 mul에 저장
        num[tmp]++;		//해당 숫자 등장 횟수 증가
    } while (mul / 10 != 0);
    num[mul]++;			//마지막 한자릿수도 증가
    for (int i : num) {
        cout << i << "\n";
    }
}
