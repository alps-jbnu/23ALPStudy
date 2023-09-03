#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
char graph[1000][1000];
bool visited[1000][1000];
int R, C;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

void bfs(int r, int c, vector<pair<int, int> > fire) {

	queue<pair<int, int> > startQ;
	queue<pair<int, int> > fireQ;
	int cnt = 0;
	startQ.push({ r,c });
	for (int i = 0; i < fire.size(); i++) {
		fireQ.push({ fire[i].first,fire[i].second });
	}

	while (!startQ.empty()) {
		//fire먼저
		int fqSize = fireQ.size();
		for (int i = 0; i < fqSize; i++) {
			int cr = fireQ.front().first;
			int cc = fireQ.front().second;
			fireQ.pop();
			for (int j = 0; j < 4; j++) {
				int nr = cr + dir[j][0];
				int nc = cc + dir[j][1];
				if (nr >= 0 && nr < R && nc >= 0 && nc < C && graph[nr][nc] != '#') {
					graph[nr][nc] = '#';
					fireQ.push({ nr,nc });
				}
			}
		}
		//상근이 이동
		int sqSize = startQ.size();
		cnt++;
		for (int i = 0; i < sqSize; i++) {
			int cr = startQ.front().first;
			int cc = startQ.front().second;
			startQ.pop();
			for (int j = 0; j < 4; j++) {
				int nr = cr + dir[j][0];
				int nc = cc + dir[j][1];
				if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
					cout << cnt<<'\n';
					return;
				}
				if (nr >= 0 && nr < R && nc >= 0 && nc < C && graph[nr][nc] != '#' && !visited[nr][nc]) {
					startQ.push({ nr,nc });
					visited[nr][nc] = true;
				}
			}
		}
	}
	
	cout << "IMPOSSIBLE"<<'\n';


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> C >> R;
		int r, c;
		vector<pair<int, int> > fire;
		//input
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> graph[i][j];
				if (graph[i][j] == '*') {
					fire.push_back({ i,j });
					
					graph[i][j]='#';
				}
				else if (graph[i][j] == '@') {
					r = i;
					c = j;
				}
			}
		}
		//solve
		bfs(r, c, fire);
	
		//reset
		memset(graph, ' ', sizeof(graph));
		memset(visited, false, sizeof(visited));
	}

	return 0;
}
