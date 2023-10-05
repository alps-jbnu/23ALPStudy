#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num[10] = { 0 };			//0부터 9사이의 숫자가 등장하는 횟수
    int n;
    cin >> n;
    while (n != 0) {				//등장 횟수를 저장하는 반복문
        num[n % 10]++;
        n /= 10;
    }
    int max=-1;
    for (int i = 0; i < 10; i++) {		//등장 횟수가 가장 많은 수 --> 필요한 세트 수
        if (num[i] >= max) {
            if (i == 6 || i == 9) {
                continue;
            }
            else {
                max = num[i];
            }
        }
    }
    if (max < (num[6] + num[9] + 1) / 2) {	//6이나 9는 서로 뒤집어서 사용 가능하기 때문에
        max = (num[6] + num[9] + 1) / 2;	//6의 갯수 + 9의 갯수 + 1 / 2 --> 6과 9의 필요한 세트 수
    }
    cout << max;
}
