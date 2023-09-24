/*
	Day: 2023.09.18
	참고 :
*/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);
	int count = 0;
	string temp1, temp2;
	cin >> temp1 >> temp2;

	int alpa[26] = { 0 };
	
	for (int j = 0; j < temp1.length(); j++) {
		alpa[temp1[j] - 'a']++;
	}
	for (int j = 0; j < temp2.length(); j++) {
		alpa[temp2[j] - 'a']--;
	}
	
	for (int j = 0; j < 26; j++) {
		if (alpa[j] != 0) {
			count += abs(alpa[j]);
		}			
	}

	cout << count << "\n";
}
