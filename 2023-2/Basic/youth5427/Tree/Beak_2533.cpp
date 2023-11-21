/*
	Day: 2023.11.21
	참고 : 트리, 다이나믹 프로그래밍
			얼리어답터가 누구인지 주체 조심!
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int max1 = 1000001;

vector<int> fri[max1];	// 각 노드 연결된 정보 저장!
bool isvist[max1] = { false };
int dp[max1][2];	// 본인이 얼리(1)일때, 본인이 얼리가 아닐(0) 때 최소 얼리어답터의 갯수
void dfs(int node) {
	isvist[node] = true;	// 현재 노드(자신) 방문 표시
	dp[node][0] = 0;	// 자신이 얼리가 아님 =>1
	dp[node][1] = 1;	// 자신이 얼리임. => 0

	for (int i = 0; i < fri[node].size(); i++) { // 0,1 
		int connect = fri[node][i];	// connect: 연결된 노드(친구)
		if (isvist[connect]) continue;	// 방문했으면 패스
		dfs(connect);					// 방문 안했으면 dfs 실행
		dp[node][0] += dp[connect][1];	// 자신이 얼리가 아니면 친구가 얼리!
		dp[node][1] += min(dp[connect][0], dp[connect][1]);	// 자신이 얼리면 친구는 얼리, !얼리 경우 중
															// 최솟값 선택!
	}
}

int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 0;
	cin >> cnt;

	for (int i = 1; i < cnt; i++) {
		int a, b;
		cin >> a >> b;

		fri[a].push_back(b);	// a와 b가 친구
		fri[b].push_back(a);	// b와 a가 친구
	}
	dfs(1);
	cout << min(dp[1][0], dp[1][1]);
}
