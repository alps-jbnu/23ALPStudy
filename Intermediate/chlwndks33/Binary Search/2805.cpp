#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,height,a;
    vector<int> vec;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> a;
        vec.push_back(a);
    }
    int st = 0;
    int en = *max_element(vec.begin(),vec.end());
    while(st <= en) {
        int mid = (st + en) / 2; //나무의 높이
        long long sum = 0; //int로 선언해서 틀렸음. 자른 나무들을 더하다보면 int 형 범위를 넘어갈 수 있음
        for(int i=0; i<n; i++) {
            if(vec[i]>mid) sum += vec[i] - mid;
        }
        if(sum >= m) { //집에 돌아갈 수 있는 경우
            ans = mid;
            st = mid + 1;
        }
        else { //집에 못 가는 경우
            en = mid - 1;
        }
    }
    cout << ans;

}