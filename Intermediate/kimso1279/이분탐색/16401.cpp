#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int M, N;
	cin >> M >> N;
	int L[1000002];
	
	for(int i=0; i<N; i++) cin >> L[i];

	int st = 0;
	int en = *max_element(L,L+N);

	while(st < en){
		int mid = (st+en+1) / 2;
		int cnt=0;
		for(int i=0; i<N; i++){
			cnt += L[i] / mid;
		}

		if(cnt >= M){
			st = mid;
		}
		else if(cnt < M){
			en = mid - 1;
		}
	}
	cout << st << "\n";
}
