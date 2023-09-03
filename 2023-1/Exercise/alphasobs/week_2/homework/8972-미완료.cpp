#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
const int MAX = 100 + 1;
const int INF = 987654321;
using namespace std;

int R, C, result = 0;
int arr[MAX][MAX];
int dir[10][2] = { {0, 0}, {1, -1}, {1, 0}, {1, 1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1} };
bool IsTrue = 0;
vector<pii> vec;
pii jongsu;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		string str; cin >> str;
		for (int j = 0; j < C; j++)
		{
			if (str[j] == 'I')
			{
				arr[i][j] = 1;
				jongsu = { i, j };
			}
			else if (str[j] == 'R')
			{
				arr[i][j] = 2;
				vec.push_back({ i, j });
			}
			else arr[i][j] = 0;
		}
	}

	string temp; cin >> temp;
	for (int i = 0; i < temp.length(); i++)
	{
		result++;
		if ()
	}

	return 0;
}