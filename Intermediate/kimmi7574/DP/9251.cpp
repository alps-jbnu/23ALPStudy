#include <bits/stdc++.h>
using namespace std;

string str1, str2;
int d[1005][1005];	//d[i][j]: i,j번째 이전까지의 LCS

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> str1 >> str2;
	
	for (int i = 1; i <= str1.length(); i++) {
		for (int j = 1; j <= str2.length(); j++) {
			if (str1[i - 1] == str2[j - 1])
				d[i][j] = d[i - 1][j - 1] + 1;	//같은 문자 개수 1개 추가
				//이전까지의 LCS의 길이에 +1 : 두 문자를 비교하기 전의 LCS의 길이에 +1하기 위해
			else
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
			//비교한 문자가 포함되어 있는 직전 LCS 중 왼, 위쪽 중 큰 값이 오게 됨
		}
	}

	cout << d[str1.length()][str2.length()] << "\n";
}