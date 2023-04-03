#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;

string board[1002];
int dist1[1002][1002];			// ��
int dist2[1002][1002];			// ����
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
//int T = 0;							// �ð��� ���� ������ �ߴµ� ��ȿ�����̴�.

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int R, C;
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		fill(dist1[i], dist1[i] + C, -1);
		fill(dist2[i], dist2[i] + C, -1);
	}

	queue<pair<int, int>> Q1;		// ��
	queue<pair<int, int>> Q2;		// ����

	for (int i = 0; i < R; i++)
		cin >> board[i];

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (board[i][j] == 'F')
			{
				Q1.push({ i, j });
				dist1[i][j] = 0;
			}
			if (board[i][j] == 'J')
			{
				Q2.push({ i,j });
				dist2[i][j] = 0;
			}
		}
	}

	while (!Q1.empty())		// ��
	{
		auto current = Q1.front();
		Q1.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = current.first + dx[dir];
			int ny = current.second + dy[dir];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue;
			if (dist1[nx][ny] >= 0 || board[nx][ny] == '#')
				continue;
			dist1[nx][ny] = dist1[current.first][current.second] + 1;
			Q1.push({ nx,ny });
		}
	}

	while (!Q2.empty())		// ����
	{
		auto current = Q2.front();
		Q2.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = current.first + dx[dir];
			int ny = current.second + dy[dir];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C)		// ���� ������ ������ ���� ��
			{
				cout << dist2[current.first][current.second] + 1 << '\n';
				return 0;
			}
			if (dist2[nx][ny] >= 0 || board[nx][ny] == '#')
				continue;
			if ((dist2[current.first][current.second] + 1) >= dist1[nx][ny] && dist1[nx][ny] != -1)
				continue;			// ���� �� ���� �ȵ�
			dist2[nx][ny] = dist2[current.first][current.second] + 1;
			Q2.push({ nx,ny });
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}
