//구글링...

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;

int n;
vector<string> name;
map<string, int> name_number;
vector<int> indegree(1000, 0);
vector<int> adj[1000];
int m;

vector<string> start_name; //각 가문의 시조들의 이름
vector<string> family_info;
vector<int> children_cnt(1000, 0); //[이름번호] = 자식의 수
vector<string> children[1000]; //[이름번호] = 자식들 이름

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;

		name.push_back(input);
		name_number.insert(make_pair(input, i));
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		string x, y;
		cin >> x >> y; //x의 조상에는 y가 있다

		int x_number = name_number[x];
		int y_number = name_number[y];

		adj[y_number].push_back(x_number);
		indegree[x_number]++;
	}

	int k = 0;
	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		if (indegree[i] == 0)
		{
			start_name.push_back(name[i]);
			q.push(i);
			k++;
		}
	}

	while (!q.empty())
	{
		int here = q.front();
		q.pop();

		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i];
			indegree[there]--;

			if (indegree[there] == 0)
			{
				children_cnt[here]++;
				children[here].push_back(name[there]);
				q.push(there);
			}
		}

		string this_info = name[here];
		this_info += (' ' + to_string(children_cnt[here]));

		sort(children[here].begin(), children[here].end());
		for (int i = 0; i < children[here].size(); i++)
		{
			this_info += (' ' + children[here][i]);
		}

		family_info.push_back(this_info);
	}

	cout << k << "\n";

	sort(start_name.begin(), start_name.end());
	for (int i = 0; i < start_name.size(); i++)
		cout << start_name[i] << " ";
	cout << "\n";

	sort(family_info.begin(), family_info.end());
	for (int i = 0; i < family_info.size(); i++)
		cout << family_info[i] << "\n";

	return 0;
}
