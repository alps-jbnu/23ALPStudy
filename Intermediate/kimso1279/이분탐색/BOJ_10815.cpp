#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[500000];
int card[500000];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	sort(arr, arr + n);

	cin >> m;
	for(int i=0; i<m; i++){
		cin >> card[i];
	}

	for(int i=0; i<m; i++){
		cout << binary_search(arr, arr + n, card[i]) << ' ';
	}
}
