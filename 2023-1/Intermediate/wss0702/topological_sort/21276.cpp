#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stdlib.h>
#include<tuple>
#include<array>
#include<vector>
#include<string.h>
#include<unordered_map>
#define MAX 100005
//계보 복원가 호석 
using namespace std;
int v, e, k;
string name[1002];//이름 저장
int indegree[1005];
vector<int>adj[1005];
unordered_map<string, int> id;
vector<int>child[1005];
queue<int> q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v;
	for (int i = 1; i <= v; i++) {
		cin >> name[i];
	}

	sort(name + 1, name + v + 1);
	for (int i = 1; i <= v; i++) {
		id[name[i]] = i;//사전순으로 번호 부여
	}
	vector<int> result;
	cin >> e;
	for (int i = 0; i < e; i++) {
		string str1, str2;
		cin >> str1 >> str2;
		adj[id[str2]].push_back(id[str1]);
		indegree[id[str1]]++;
	}
	for (int i = 1; i <= v; i++) {
		if (!indegree[i]) result.push_back(i);//가문의 시조 저장
	}
	cout << result.size() << "\n";
	for (int i : result) {
		cout << name[i] << " ";
	}
	cout << "\n";
	for (int i = 1; i <= v; i++) {
		sort(adj[i].begin(), adj[i].end());
		for (int c : adj[i]) {
			if (indegree[c] - indegree[i] == 1)child[i].push_back(c);//indegree의 차이가 1이면, 자식이다.
		}
	}
	for (int i = 1; i <= v; i++) {
		int size = child[i].size();
		cout << name[i] << " " << size << " ";
		for (int c : child[i]) {
			cout << name[c] << " ";
		}
		cout << "\n";
	}

}
