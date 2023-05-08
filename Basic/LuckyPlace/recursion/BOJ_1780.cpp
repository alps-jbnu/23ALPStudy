#include <iostream>
using namespace std;

int paper[2200][2200];
int arr[3];						// -1, 0, 1의 개수를 저장(전역변수이므로 0으로 자동 초기화)
int N;

bool is_same_num(int x, int y, int n)		// x, y는 사각형의 왼쪽 위 시작점 n은 검사할 범위
{
	for (int i = x; i < x + n; i++)				// 끝나는 조건에 시작점을 더해줘야 한다.
	{
		for (int j = y; j < y + n; j++)
		{
			if (paper[x][y] != paper[i][j])
				return false;
		}
	}
	return true;
}

void recursion(int x, int y, int n)
{
	if (is_same_num(x, y, n))
	{
		arr[paper[x][y] + 1]++;	
		return;
	}
	else
	{
		int a = n / 3;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				recursion(x + a * i, y + a * j, a);			// 재귀시작, x, y(시작점)을 더해줘야 한다.(힌트 봄)
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> paper[i][j];

	recursion(0, 0, N);

	for (int i = 0; i < 3; i++)			// 출력
		cout << arr[i] << "\n";
	return 0;
}