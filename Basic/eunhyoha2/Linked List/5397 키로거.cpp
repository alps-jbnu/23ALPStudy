#include <iostream>
#include <list>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0); // 출력시간 도움
	cin.tie(0); cout.tie(0);

	int T;
	list<char> I;
	list<char>::iterator t; //반복자
	string L; // 문자열
	cin >> T; // T 입력받기

	for (int i = 0; i < T; i++) {
		cin >> L;
		I.clear();
		t = I.begin();
		for (int j = 0; j < L.length(); j++) {
			if (L[j] == '<' && t != I.begin()) t--;
			else if (L[j] == '>' && t != I.end()) t++;
			else if (L[j] == '-' && t != I.begin()) t = I.erase(--t);
			else if (L[j] != '<' && L[j] != '>' && L[j] != '-') I.insert(t, L[j]);
		}
		for (t = I.begin(); t != I.end(); t++) 
			cout << *t;
		cout << '\n';
	}
	return 0;
}