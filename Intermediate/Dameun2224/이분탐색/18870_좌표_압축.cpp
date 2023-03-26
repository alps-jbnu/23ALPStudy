#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int x[1000005];
vector<int> uni;	// unique

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		uni.push_back(x[i]);
	}
	/*
	* unique 함수를 실행하기 전 정렬되어 있어야 한다.
	* unique 함수는 반복되는 값을 뒤로 밀어내고, 
	* 밀어낸 값의 첫 번째 값의 인덱스를 반환한다.
	* (결과가 {1 2 3 4 5 6 1 2 4} 라고 할 때, 6을 반환)
	*/
	sort(uni.begin(), uni.end());
	uni.erase(unique(uni.begin(), uni.end()), uni.end());

	/*
	* lower_bound 함수를 실행하기 전 정렬되어 있어야 한다.
	* 찾으려는 key 값보다 같거나 큰 숫자가 몇 번째에서 처음 등장하는지 찾는다.
	* 반환형이 iterator이므로 인덱스를 알고 싶다면 첫번째 주소를 빼주어야 한다.
	*/
	for (int i = 0; i < n; i++) {
		cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' ';
	}

	return 0;
}
