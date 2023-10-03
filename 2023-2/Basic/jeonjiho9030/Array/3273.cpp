
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, count = 0;
    int arr[1000001] = {};		//수열을 저장하는 배열
    bool ch[2000001];		//해당 숫자가 수열에 포함되는지 저장하는 bool 배열
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        ch[tmp] = true;		//입력받은 수가 수열에 존재한다고 표시
        arr[i] = tmp;
    }
    cin >> x;
    for (int i = 0; i < n; i++) {
        if (x-arr[i]>0 && ch[x - arr[i]]) {	//배열을 순회하면서 x가 되기위해 필요한 수가 존재한다면 count 증가
            count++;
        }
    }
    cout << count / 2;		//중복으로 체크 됐기 때문에 2로 나눈 값 출력
}
