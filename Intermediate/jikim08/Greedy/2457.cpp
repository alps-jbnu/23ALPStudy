#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> Mdate = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	
	vector<pair<int, int>> flowering(N, { 0,0 });
	int M, D;

	for (int i = 0; i < N; i++) {
		cin >> M >> D;				//월 일 입력 받기
		for (int j = 0; j < M; j++)
			flowering[i].second += Mdate[j];		//개화시기 일단위로 저장
		flowering[i].second += D;
		cin >> M >> D;				//꽃 지는 시기 일단위로 저장
		for (int j = 0; j < M; j++)
			flowering[i].first += Mdate[j];
		flowering[i].first += D;
	}

	int startMax = Mdate[1] + Mdate[2] + 1;		//3월 1일
	int endMin = 0;
	for (int i = 1; i <= 11; i++) {
		endMin += Mdate[i];
	}	//11월 30일

	sort(flowering.begin(), flowering.end());
	int answer = 0;
	int checkIndex = 0;			//for문 여까지 돌리라
	bool complete = false;		//마지막 요소 잘 찾았으면 true

	for (int i = N - 1; i >= checkIndex; i--) {		//지는 시기가 늦은걸 골라야하니까 밑에서부터 확인하기
		if (flowering[i].second <= startMax) {		//지는 시가가 늦으면서 피는 시기도 오케이면
			if (flowering[i].first == flowering[i].second)	continue;
			answer++;				//꽃 추가
			if (flowering[i].first > endMin) {		//마지막 꽃이면
				complete = true;			//탈출
				break;
			}
			startMax = flowering[i].first;		//이 꽃이 지는 시기를 다음 꽃 개화시기의 커트라인으로
			checkIndex = i+1;					//확인할 인덱스 갱신
			i = N;		//다시 밑에서부터
		}
	}

	if (complete) {
		cout << answer;
	}
	else {
		cout << 0;
	}
}
