#include <iostream>
using namespace std;
const int MX = 100005;
int dat[MX];
int pos = 0;
void Push(int x) { dat[pos++] = x; }
int Top() { return dat[pos - 1]; }
void Pop() { pos--; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	int n; cin >> n;
	string ans;

	int cnt = 1;	//n까지의 수열 중 현재 처리가 필요한 숫자

	while (n--) {
		int t;
		cin >> t;
		while (cnt <= t) {
			Push(cnt++);
			ans += "+\n";
		}
		if (Top() != t) {
			cout << "NO\n";
			return 0;
		}
		Pop();
		ans += "-\n";
	}
	cout << ans;
}
