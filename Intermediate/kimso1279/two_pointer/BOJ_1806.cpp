#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
  	cin.tie(0);

	int n, s;
	cin >> n >> s;

	int a[n];
	for(int i=0; i<n; i++) cin >> a[i];
	//오답이유1. sort(a,a+n)을 넣어 정렬을 해버려서 합에 영향을 미침

	int mn = 0x7fffffff, total = a[0], en=0;

	for(int st=0; st<n; st++){
		while(en<n && total < s){
			en++; //en+st가 s이상이 될 때 까지 en증가
			if(en != n){
				total += a[en];
			}
		}
		if(en==n) break; // en이 범위 밖을 벗어날 시 종료
		mn = min(mn, en-st+1); // s이상이 되면 가장 작은 len으로 mn 값 갱신
		total -= a[st];
	}

	if(mn == 0x7fffffff) mn = 0; // 오답이유2. 합이 s이상이 되지 않을 때 예외처리 해주지 않음
	cout << mn;
}
