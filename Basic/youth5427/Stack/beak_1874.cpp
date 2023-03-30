/*

	Day: 2023.03.30
	참고 : 스택(stack), 입력한 숫자까지 오름차순 스택올리고(+) 입력한 숫자까지 pop실행(-)

*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);
	int N = 0;
	int count = 1;
	cin >> N;
	stack<int> s;
	vector<char> op;
	
	while (N--) {
		int temp = 0;
		cin >> temp;		// temp: 입력하는 수
		while (count <= temp) {	// 입력된 숫자까지 스택 넣기(+추가)
			op.push_back('+');
			s.push(count);
			count++;
		}
		if (s.top() == temp) {	// 입력된 숫자가 스택 top과 같으면 pop()실행
			s.pop();
			op.push_back('-');
		}
		else {					// a로 입력받은게 top에 없으면 빼는게 불가능하다
			cout << "NO\n";
			return 0;
		}
	}
	for (int i = 0; i < op.size(); i++)
		cout << op[i] << "\n";
}
