#include <bits/stdc++.h>
using namespace std;

int N;
int paper[2200][2200];
int cnt[3]; 

bool check(int n, int x, int y) {
  	for (int i = x; i < x + n; i++)
  	for (int j = y; j < y + n; j++)
    	if (paper[x][y] != paper[i][j])
    		return false;
  	return true;
}

void recursion(int n, int x, int y)
{
  	if (check(n, x, y)) {
    	cnt[paper[x][y] + 1] += 1;
    	return;
  	}
  
  	int size = n / 3;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
    		recursion(size, x + i * size, y + j * size);
}

int main() {
	ios::sync_with_stdio(0);
  	cin.tie(0);
  	
  	cin >> N;
  	
	for (int i = 0; i < N; i++)
  		for (int j = 0; j < N; j++)
    		cin >> paper[i][j];
  
  	recursion(N, 0, 0);
  
  	for (int i = 0; i < 3; i++) 
	  	cout << cnt[i] << "\n";
	
	
}
