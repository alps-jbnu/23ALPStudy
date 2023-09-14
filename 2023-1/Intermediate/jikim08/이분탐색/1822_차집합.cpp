#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int Acount, Bcount;
	cin >> Acount >> Bcount;

	vector<long long> A(Acount);
	vector<long long> B(Bcount);
	

	for (int i = 0; i < Acount; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < Bcount; i++) {
		cin >> B[i];
	}
	//여기까지 입력 부분

	vector<long long> answer;		//정답을 저장할 벡터

	int SubCnt = 0;			//차집합 요소 수

	sort(B.begin(), B.end());	//정렬

	for (int i = 0; i < Acount; i++) {
		if (!binary_search(B.begin(), B.end(), A[i])) {		//A[i]의 요소를 탐색 후 B에 없으면 answer벡터에 넣음
			SubCnt++;
			answer.push_back(A[i]);
		}
	}

	cout << SubCnt << endl;
	sort(answer.begin(), answer.end());	 //정렬

	for (long long ans : answer) {
		cout << ans << ' ';
	}
	

}
