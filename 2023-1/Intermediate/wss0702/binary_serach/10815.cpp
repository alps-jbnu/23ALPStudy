#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
//10815
using namespace std;

int N, M;
int arr[500005];
vector<int>answer;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int find_num;
		cin >> find_num;
		if (binary_search(arr, arr + N, find_num)) answer.push_back(1);
		else answer.push_back(0);
	}
	for (int i : answer) {
		cout << i << " ";
	}
	
	
}
