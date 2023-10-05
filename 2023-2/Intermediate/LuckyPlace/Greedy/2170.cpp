#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>		// for std::tie()
using namespace std;

vector<pair<int, int>> v;			// 배열로 선언하면 용량이 커서 에러

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end());
	int l, r;
	long long ans = 0;
	tie(l, r) = v[0];
	for (int i = 0; i < n; i++)
	{
		int cur_l, cur_r;
		tie(cur_l, cur_r) = v[i];
		if (cur_l <= r && cur_r >= r)			// l 경계는 은 sorting을 해서 최저일 것이므로 r 경계만 검사
			r = cur_r;			// r 경계 늘리기
		else if (cur_l > r)
		{
			ans += r - l;
			l = cur_l;			// 새로운 선으로 갱신
			r = cur_r;
		}
		// 나머지 경우는 완전히 겹치는 경우이므로 버린다.
	}
	ans += r - l;		// 마지막 선분 더하기
	cout << ans;

	return 0;
}
