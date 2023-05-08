#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
  	cin.tie(0);

	int n, m;
	cin >> n >> m;
    
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];

	int sum = a[0], en=0, st=0, cnt=0;

	while(st <= en && en<n){
		if(sum < m) sum += a[++en];
        else if(sum == m){
            cnt++;
            sum += a[++en];
        }
        else if(sum > m){
            sum -= a[st++];
            // 오답이유 -> st가 en보다 큰 경우를 처리해주지 않음
            if(st > en){
                en = st;
                sum = a[st];
            }
        }
    }

	cout << cnt;
	
}
