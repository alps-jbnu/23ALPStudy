/*
	Day: 2023.09.19
	참고 : 반복자(iterator) 사용 / 포인터와 비슷한 역할 / 컨테이너 요소를 순회하거나 조작할 때 사용.
*/

#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; cin >> N;

	for (int i = 0; i < N; i++) {
		list<char> L;
		list<char>::iterator t = L.begin();
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.length(); j++) {
			if (temp[j] == '>') {
				if (t != L.end())t++;
			}
			else if (temp[j] == '<') {
				if (t != L.begin())t--;
			}
			else if (temp[j] == '-') {
				if (t != L.begin()) {
					// erase 함수 호출 후 t iterator 가 무효화. erase(--t) 을 호출한 후 t 를 다시 설정
					t = L.erase(--t);
				}
			}
			else L.insert(t, temp[j]);
		}
		for(char c : L) cout << c;
        cout << "\n";
	}
}
