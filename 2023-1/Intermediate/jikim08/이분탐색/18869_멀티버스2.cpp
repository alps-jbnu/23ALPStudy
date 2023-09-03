#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> press_coor(vector<int> V) {
	vector<int> pressV = V;
	sort(V.begin(), V.end());
	V.erase(unique(V.begin(), V.end()), V.end());	//중복제거
	
	for (int i = 0; i < pressV.size(); i++) {
		int idx = lower_bound(V.begin(), V.end(), pressV[i]) - V.begin();
		pressV[i] = idx;
	}
	
	return pressV;
}

int main() {
	int Uni, Plan;
	cin >> Uni >> Plan;

	vector<vector<int>> Universe(Uni, vector<int>(Plan));	//우주를 벡터로 저장
	vector<vector<int>> Univ_press;		//우주 좌표 압축 벡터
	
	for (int i = 0; i < Uni; i++) {
		for (int j = 0; j < Plan; j++) {
			cin >> Universe[i][j];
		}
	}

	for (int i = 0; i < Uni; i++) {		//좌표 압축
		Univ_press.push_back(press_coor(Universe[i]));
	}
	int answer = 0;

	for (int i = 0; i < Uni-1; i++) {
		for (int j = i + 1; j < Uni; j++) {
			if (Univ_press[i] == Univ_press[j]) {
				answer++;
			}
		}
	}
	cout << answer;

}
