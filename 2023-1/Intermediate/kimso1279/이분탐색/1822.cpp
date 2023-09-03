#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int na, nb;
	cin >> na >> nb;

	vector<int> a(na), b(nb), arr;

	for(int i=0; i<na; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	
	for(int i=0; i<nb; i++){
		cin >> b[i];
	}
	sort(b.begin(), b.end());

	for(int i=0; i<na; i++){
		if(!binary_search(b.begin(), b.end(), a[i])){
			arr.push_back(a[i]);
		}
	}
	cout << arr.size() << '\n';
	for(int i=0; i<arr.size(); i++ ){
		cout << arr[i] << ' ';
	}
}
