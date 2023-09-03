#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,a;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> a;
        vec.push_back(a);
    }
    int st = 1;
    int en = *max_element(vec.begin(),vec.end());
    while(st<=en) {
        int mid = (st+en) / 2; //조카에게 줄 수 있는 과자의 길이
        int count =0;
        for(int i=0; i<m; i++)
            count += vec[i] / mid;
        if(count >= n) { //과자를 줄 수 있는 경우
                st = mid + 1;
                ans = mid;
        }
        else { //과자를 줄 수 없는 경우
                en = mid - 1;
        }
    }
    cout << ans;

}