/*
	Day: 2023.09.18
	참고 :
*/
#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {	
		string temp, temp1;
		bool result = false;

		cin >> temp >> temp1;
		int alpa[26] = { 0 };

		// ☆처음부터 길이가 다르면 바로 판단!!!!☆
		if (temp.length() != temp1.length()) {
			cout << "Impossible\n";
			continue;
		}
		
		// 길이가 다를 경우 오버플로우 발생!!
		for (int j = 0; j < temp.length(); j++) {
			alpa[temp[j] - 'a']++;
			alpa[temp1[j] - 'a']--;
		}

		for (int j = 0; j < 26; j++) {
			if (alpa[j] != 0) {
				result = false;
				break;
			}
			else
				result = true;
		}

		if (result)
			cout << "Possible\n";
		else
			cout << "Impossible\n";
	}
}
