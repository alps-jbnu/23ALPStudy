#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int f,s,g,u,d;
bool vis[1000001];
queue <int> q;

int bfs(int a) {
    q.push(a);
    vis[a] = true;
    int h = 0; 
    while (!q.empty()) {
        int size = q.size(); 
        for (int i = 0; i < size; i++) {
            a = q.front();
            q.pop();
            if (a == g) {
                return h;
            }
            if (a + u <= f && !vis[a + u]) { 
                q.push(a + u);
                vis[a + u] = true;
            }
            if (a - d > 0 && !vis[a - d]) { 
                q.push(a - d);
                vis[a - d] = true;
            }
        }
        h++;
    }
    return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> f >> s >> g >> u >> d;

	int b=bfs(s);
	if (b == -1) {
		cout << "use the stairs";
	}
	else {
		cout << b;
	}
}
