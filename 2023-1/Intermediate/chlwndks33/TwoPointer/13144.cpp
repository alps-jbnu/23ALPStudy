#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int n;
long long res;
bool vis[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n; 
	vector<int> v(n);
	for(int i = 0; i < n; i++)
        cin >> v[i];
	int end=0;
	for(int start = 0; start < n; start++) {
		while(end < n) {
			if(vis[v[end]]) break;
			vis[v[end]]=true;
			end++; 
		}
		res+=(end-start);
		vis[v[start]]=false;
	}
	cout << res;
	return 0;
}