#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
#define pip pair<int, pii>
const int MAX = 250000 + 1;
using namespace std;

struct Info {
	int s, t, cnt;
};

int main(void)
{
	int c;
	cin >> c;

	while (c--)
	{
		int s, t;
		cin >> s >> t;

		queue<Info> q;
		q.push({ s, t, 0 });

		while (!q.empty())
		{
			Info now = q.front();
			q.pop();

			if (now.s > now.t)
				continue;

			if (now.s == now.t)
			{
				cout << now.cnt << '\n';
				break;
			}

			Info next = { now.s * 2, now.t + 3, now.cnt + 1 };
			q.push(next);
			next = { now.s + 1, now.t, now.cnt + 1 };
			q.push(next);
		}
	}

	return 0;
}