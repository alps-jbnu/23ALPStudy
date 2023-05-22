#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
#define pip pair<int, pii>
const int MAX = 10 + 1;
using namespace std;

int N, result = 0;
string str;
int arr[MAX][MAX];
int DP[MAX][MAX];

int calculate(int a, int b, char op)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N; 
	cin >> str;

	for(int i = 0; i < MAX; i++)
	{
		for(int j = 0; j < MAX; j++)
		{
			arr[i][j] = INT_MIN;
			DP[i][j] = INT_MAX;
		}
	}

	int Size = N / 2 + 1;
	for(int i = 0; i < Size; i++)
	{
		arr[i][i] = DP[i][i] = str[i * 2] - '0';
	}

	for (int cnt = 1; cnt < Size; cnt++)
	{
		for (int idx = 0; idx < Size - cnt; idx++)
		{
			for (int i = 1, j = cnt; i <= cnt; i++, j--)
			{
				int Index = (idx + cnt - j) * 2 + 1;
				char op = str[Index];

				int candidates[4] = {
					calculate(arr[idx][idx + cnt - j], arr[idx + i][idx + cnt], op),
					calculate(arr[idx][idx + cnt - j], DP[idx + i][idx + cnt], op),
					calculate(DP[idx][idx + cnt - j], arr[idx + i][idx + cnt], op),
					calculate(DP[idx][idx + cnt - j], DP[idx + i][idx + cnt], op)
				};

				sort(candidates, candidates + 4);

				arr[idx][idx + cnt] = max(arr[idx][idx + cnt], candidates[3]);
				DP[idx][idx + cnt] = min(DP[idx][idx + cnt], candidates[0]);
			}
		}
	}
	
	result = arr[0][Size - 1];
	cout << result;

    return 0;
}