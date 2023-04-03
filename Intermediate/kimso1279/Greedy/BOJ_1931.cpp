#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, int> arr[100005]; // => 오답 이유 first는 end, second는 start

int main(void) {
    int n, t=0, cnt=0; // 회의 수, 현재시간, 가능 회의 수
    cin >> n;
    
    for(int i=0; i<n; i++) cin >> arr[i].second >> arr[i].first;
    sort(arr, arr+n);

    for(int i=0; i<n; i++){
        if(t > arr[i].second) continue;
        cnt++;
        t = arr[i].first;
    }

    cout << cnt;
}
