#include <iostream>
using namespace std;
bool idx_arr[2000001];	//0 0 ... 0
int a[100001] = {};	//simple sol for C262...
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	 
	int pair = 0;
	int n, x;
	//int* a;
	//int a[100000]; //Warning C262: exceeds stack size 16384

	cin >> n;
	//a = new int[1000001];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> x;


	for (int j = 0; j < n; j++) {
		//※합하면 x가 되는 element가 등장했으면 ok, 없으면 해당 번호 등장 횟수 1 증가
		if (x-a[j]>0&&idx_arr[x - a[j]])
			//x-a[j]>0&& 꼭 추가해줘야 함.
			//if x=9, a[j]=10 --> arr[-1]: OutOfBound_runtimeError
			pair++;
		idx_arr[a[j]]=true;
	}
	cout << pair;
	//delete[] a;
}
