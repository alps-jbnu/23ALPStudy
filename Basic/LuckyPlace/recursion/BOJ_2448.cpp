#include <iostream>
using namespace std;

const int MAX_NUM = 3075;				//  1024 * 3 넉넉잡아 + 3
char star_board[MAX_NUM][MAX_NUM * 2];		// 열이 정확히는 MAX_NUM * 2 - 1개 필요하지만 넉넉하게 잡아줌

void print_star(int r, int c)		// 제일 작은 삼각형 별을 찍는 함수
{
	star_board[r][c] = '*';
	star_board[r + 1][c - 1] = '*';
	star_board[r + 1][c + 1] = '*';
	for (int i = c - 2; i <= c + 2; i++)
		star_board[r + 2][i] = '*';
}

void recursion(int r, int c, int n)		// r, c는 print_star에 전달해줄 처음 위치, n은 초기 입력값
{
	if (n == 3)				// base conditon
	{
		print_star(r, c);
		return;
	}
	else
	{
		int half = n / 2;			// 2^n이므로 2로 나눠 준다
		// 3개의 삼각형이 프렉탈 구조로 찍히므로 재귀함수 3개를 호출해준다.
		recursion(r, c, half);	
		recursion(r + half, c - half, half);
		recursion(r + half, c + half, half);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	recursion(0, n - 1, n);					// 초기 위치 : row = n -1, column = 0
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n * 2 - 1; j++)
		{
			if (star_board[i][j] == '*')
				cout << '*';
			else
				cout << ' ';
		}
		cout << "\n";
	}

	return 0;
}