#include <iostream>
using namespace std;

bool paper[130][130];		//0과 1로 표현 가능하므로 bool로 2차원 배열 생성(0은 흰색 1은 파란색 의미)
int arr[2];							// 0번째는 흰색 1번째는 파란색 저장
int N;		// 정사각형 한변의 길이

bool is_same_color(int x, int y, int n)		//사각형 전체가 같은 색인지 확인하는 함수
{
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (paper[x][y] != paper[i][j])
				return false;
	return true;
}

void recursion(int x, int y, int n)		//x, y는 시작점, n은 한 변의 길이
{
	if (is_same_color(x, y, n))
	{
		arr[paper[x][y]]++;
		return;
	}
	else
	{
		int half = n / 2;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				recursion(i * half + x, j * half + y, half);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> paper[i][j];

	recursion(0, 0, N);

	for (int i = 0; i < 2; i++)
		cout << arr[i] << "\n";
	return 0;
}