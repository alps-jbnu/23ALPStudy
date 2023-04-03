#include <iostream>
#include <queue>
using namespace std;

int dist[100002];
int dx[3] = { 1,-1,2 };			// 2는 *2

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	queue<int> Q;
	int N, K;				// N : 수빈이가 있는 위치, K : 동생이 있는 위치
	cin >> N >> K;
	Q.push(N);
	for (int i = 0; i < 100002; i++)
		dist[i] = -1;
	dist[N] = 0;
	//while (!Q.empty())						// 반복 조건을 queue가 다 끝날때하면 안됨
	while (dist[K] == -1)
	{
		auto current = Q.front();
		Q.pop();
		for (int dir = 0; dir < 3; dir++)
		{
			int position;							// 수빈이 위치
			if (dx[dir] == 2)						// 2배 이동
				position = current * 2;
			else                                      // +1 -1 이동
				position = current + dx[dir];
			if (position < 0 || position > 100000)			// 범위 밖으로 나가는 경우
				continue;
			if (dist[position] >= 0)								// 이미 갔던 위치인 경우
				continue;
			dist[position] = dist[current] + 1;
			Q.push(position);
			/*if (position == K)
			{
				cout << dist[position];
				return 0;
			}*/
		}
	}
	cout << dist[K];
	return 0;
}