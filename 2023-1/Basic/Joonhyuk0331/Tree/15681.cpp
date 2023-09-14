#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int answer[200001];
bool vis[200001];
vector<int> v[200001];
int N, R, Q;
int a, b, x;

int funtion(int cur){
	vis[cur] = true;

	for (int i = 0; i < v[cur].size(); i++){
		int next = v[cur][i];
		if (!vis[next]){
			answer[cur] += funtion(next);
		}
	}

	return answer[cur];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> R >> Q;

	for (int i = 0; i < N - 1; i++){
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
		answer[i] = 1;

	funtion(R);

	for (int i = 0; i < Q; i++){
		cin >> x;
		cout << answer[x] << '\n';
	}
}
