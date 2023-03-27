#include<bits/stdc++.h>
using namespace std;

int n, m,jx,jy;
string s;
vector<pair<int, int>> vec;
char board[105][105];
int dx[9] = { 1,1,1,0,0,0,-1,-1,-1 };
int dy[9] = { -1,0,1,-1,0,1,-1,0 ,1};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'I') {
				jx = i;
				jy = j;
			}
			else if (board[i][j] == 'R') {
				vec.push_back({ i,j });
			}
		}
	}
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		bool vis[105][105];
		memset(vis, false, sizeof(vis));
		int a = s[i] - '0' - 1;
		board[jx][jy] = '.';
		jx += dx[a];
		jy += dy[a];
		if (board[jx][jy] == 'R') {
			cout << "kraj " << i + 1;
			return 0;
		}
		board[jx][jy] = 'I';
		
		bool chk = 0; 
		set<pair<int, int>> S;
		for (int j = 0; j < vec.size(); j++) {
			int mn = INT_MAX;
			int x, y;
			for (int k = 0; k < 9; k++) {
				int xx = vec[j].first + dx[k];
				int yy = vec[j].second + dy[k];
				if (xx < 0 || yy < 0 || xx >= n || yy >= m)	continue;
				int ax = jx - xx;
				int ay = jy - yy;
				int g = abs(ax) + abs(ay);
				if (mn > g) {
					x = vec[j].first + dx[k];
					y = vec[j].second + dy[k];
					mn = g;
				}
			}
			if (board[x][y] == 'R'&&vis[x][y]) {
				chk = 1;
				if(!vis[vec[j].first][vec[j].second])	board[vec[j].first][vec[j].second] = '.';
				vec.erase(vec.begin() + j);
				--j;
				S.insert({ x,y });
				continue;
			}
			else if (board[x][y] == 'I') {
				cout << "kraj " << i + 1;
				return 0;
			}
			board[x][y] = 'R';
			if (!vis[vec[j].first][vec[j].second])	board[vec[j].first][vec[j].second] = '.';
			vis[x][y] = 1;
			vec[j] = { x,y };
		}
		if (chk) {
			for (auto p : S) {
				for (int q = 0; q < vec.size(); q++) {
					if (p.first == vec[q].first && p.second == vec[q].second) {
						vec.erase(vec.begin() + q);
						break;
					}
				}
				board[p.first][p.second] = '.';
			}
		}
	}
	for (int i = 0; i < n; i++){ 
		for (int j = 0; j < m; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}	
 }