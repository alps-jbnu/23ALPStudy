#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
using namespace std;

string mk_num;
int mk_num_leng;
vector<int> max_ans;
vector<int> min_ans;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> mk_num;
	mk_num_leng = mk_num.length();

	int temp = 0;

	for (int i = 0; i < mk_num_leng; i++) {
		if (mk_num[i] == 'K') {
			max_ans.push_back(5);

			for (; temp < i; temp++) {
				max_ans.push_back(0);
			}
			temp = i + 1;
		}
	}

	if (max_ans.size() != mk_num_leng) {
		for (int i = temp; i < mk_num_leng; i++) {
			max_ans.push_back(1);
		}
	}

	temp = 0;
	int m_count = 0;

	for (int i = 0; i < mk_num_leng; i++) {

		if (mk_num[i] == 'K') {
			if (m_count != 0) {
				min_ans.push_back(1);
				for (int j = 0; j < m_count - 1; j++) {
					min_ans.push_back(0);
				}
				m_count = 0;
			}
			min_ans.push_back(5);
		}
		else {
			m_count++;
		}
	}

	if (min_ans.size() != mk_num_leng) {
		min_ans.push_back(1);
		for (int j = 0; j < m_count - 1; j++) {
			min_ans.push_back(0);
		}
	}

	for (auto a : max_ans) {
		cout << a;
	}
	cout << '\n';

	for (auto a : min_ans) {
		cout << a;
	}
}
