#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N;
	cin >> N;
	deque<int> DQ;
	for (int i = 1; i <= N; i++)
		DQ.push_back(i);
	int n;
	cin >> n;
	int count = 0;
	while (n--)
	{
		int x;
		cin >> x;
		int direction = find(DQ.begin(), DQ.end(), x) - DQ.begin();
		while (x != DQ.front())
		{
			if (direction < (DQ.size() - direction))
			{
				DQ.push_back(DQ.front());
				DQ.pop_front();
			}
			else
			{
				DQ.push_front(DQ.back());
				DQ.pop_back();
			}
			count++;
		}
		DQ.pop_front();
	}
	cout << count << endl;
	return 0;
}
