#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int L[1000002];
	
	for(int i=0; i<n; i++) cin >> L[i];

	int st = 0;
	int en = *max_element(L,L+n);

	while(st < en){
		int mid = (st+en+1) / 2;
		long long cnt=0;
		for(int i=0; i<n; i++){
			if(L[i] <= mid) continue;
			cnt += (L[i] - mid);
		}

		if(cnt >= m){
			st = mid;
		}
		else if(cnt < m){
			en = mid - 1;
		}
	}
	cout << st;
}
