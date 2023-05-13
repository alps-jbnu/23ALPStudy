#include<bits/stdc++.h>
using namespace std;

int n, t;
int Map[9][9];
bool row[9][10];
bool col[9][10];
bool square[3][3][10];
bool tile[10][10];
bool flag, Inp_flag;

void init() {
	flag = 0;
	memset(Map, 0, sizeof(Map));
	memset(row, false, sizeof(row));
	memset(col, false, sizeof(col));
	memset(square, false, sizeof(square));
	memset(tile, false, sizeof(tile));
}

bool check(int x, int y, int n1, int n2, char c) {

	if (c == 'G') {
		if (row[x][n1] || row[x][n2])	return false;
		if (col[y][n1] || col[y + 1][n2])	return false;
		if (square[x / 3][y / 3][n1] || square[x / 3][(y + 1) / 3][n2])	return false;
		return true;
	}
	else {
		if (row[x][n1] || row[x + 1][n2])	return false;
		if (col[y][n1] || col[y][n2])	return false;
		if (square[x / 3][y / 3][n1] || square[(x + 1) / 3][y / 3][n2])	return false;
		return true;
	}
}
void makevisit(int x, int y, int n1, int n2, char c, bool t) {
	tile[n1][n2] = t;
	tile[n2][n1] = t;

	if (c == 'G') {
		row[x][n1] = row[x][n2] = t;
		col[y][n1] = col[y + 1][n2] = t;
		square[x / 3][y / 3][n1] = square[x / 3][(y + 1) / 3][n2] = t;

		if (t) {
			Map[x][y] = n1;
			Map[x][y + 1] = n2;
		}
		else Map[x][y] = Map[x][y + 1] = 0;
	}
	else {
		row[x][n1] = row[x + 1][n2] = t;
		col[y][n1] = col[y][n2] = t;
		square[x / 3][y / 3][n1] = square[(x+1) / 3][y / 3][n2] = t;
		if (t) {
			Map[x][y] = n1;
			Map[x+1][y] = n2;
		}
		else Map[x][y] = Map[x+1][y] = 0;
	}
}

void dfs(int idx) {
	if (flag)	return;
	if (idx == 81) {
		flag = true;
		cout << "Puzzle " << t << '\n';
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << Map[i][j];
			}
			cout << "\n";
		}
	}
	int x = idx / 9;
	int y = idx % 9;
	
	if (Map[x][y] != 0)	dfs(idx + 1);
	else {
		if (y <= 7 && Map[x][y + 1] == 0) {
			for (int i = 1; i <= 9; i++) {
				for (int j = i + 1; j <= 9; j++) {
					if (tile[i][j] == false) {
						if (check(x, y, i, j,'G')) {
							makevisit(x, y, i, j, 'G', true);
							dfs(idx + 2);
							makevisit(x, y, i, j, 'G', false);
						}
						if (check(x, y, j, i, 'G')) {
							makevisit(x, y, j, i, 'G', true);
							dfs(idx + 2);
							makevisit(x, y, j, i, 'G', false);
						}
					}
				}
			}
		}
		if (x <= 7 && Map[x + 1][y] == 0) {
			for (int i = 1; i <= 9; i++) {
				for (int j = i + 1; j <= 9; j++) {
					if (!tile[i][j]) {
						if (check(x, y, i, j, 'S')) {
							makevisit(x, y, i, j, 'S', true);
							dfs(idx + 1);
							makevisit(x, y, i, j, 'S', false);
						}
						if (check(x, y, j, i, 'S')) {
							makevisit(x, y, j, i, 'S', true);
							dfs(idx + 1);
							makevisit(x, y, j, i, 'S', false);
						}
					}
				}
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (1) {
		cin >> n;
		++t;
		init();
		if (n == 0) {
			return 0;
		}
		for (int i = 0; i < n; i++) {
			int num1, num2;
			string p, p1;
			cin >> num1 >> p >> num2 >> p1;

			int x = p[0] - 'A';
			int y = p[1] - '0' - 1;
			int xx = p1[0] - 'A';
			int yy = p1[1] - '0' - 1;

			tile[num1][num2]=1;
			tile[num2][num1] = 1;

			Map[x][y] = num1;
			Map[xx][yy] = num2;

			row[x][num1] = 1;
			row[xx][num2] = 1;

			col[y][num1] = 1;
			col[yy][num2] = 1;

			square[x / 3][y / 3][num1] = 1;
			square[xx / 3][yy / 3][num2] = 1;
		}

		for (int i = 1; i <= 9; i++) {
			string pos;
			cin >> pos;
			int x = pos[0] - 'A';
			int y = pos[1] - '0' - 1;

			row[x][i] = true;
			col[y][i] = true;
			square[x / 3][y / 3][i] = 1;
			Map[x][y] = i;
		}
		dfs(0);
	}

}