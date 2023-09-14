#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> m >> n;
	pair<int, int> univ[101][10010];
	
	for(int i=0; i<m; i++){
		for(int j=0, size; j<n; j++){
			cin >> size; 
			univ[i][j].first = size;
			univ[i][j].second = j;
		}
		sort(&univ[i][0], &univ[i][n]);
	}

	int cnt=0; // 균등 우주 개수

	for(int i=0; i<m-1;i++){
		for(int j=i+1; j<m; j++){
			bool eq = true;
			for(int k=0; k<n; k++){
				if(univ[i][k].second != univ[j][k].second){
					eq = false;
					break;
				}else{
					if( i != (n-1)){
						if((univ[i][k].first < univ[i][k+1].first) != (univ[j][k].first < univ[j][k+1].first)){
							eq = false;
							break;
						}
					}
				}
			}
			if(eq == true) cnt++;
		}
	}

	cout << cnt << "\n";
}
