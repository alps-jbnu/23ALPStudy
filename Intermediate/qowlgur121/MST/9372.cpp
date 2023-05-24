#include <iostream>
using namespace std;
/*
노드 개수 -1이 간선개수이면 가장 적은 종류의 비행기를 타고 가는 것과 동일
*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	int n, m;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> n >> m;
		
		for (int j = 0; j < m; j++) {
			int a, b;
			std::cin >> a >> b;
		}
		std::cout << n - 1 << "\n";
	}
	return 0;
}
