#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,a;
    vector<int> vec;
    long long count =0; // 10000C3 은 int형 범위를 넘기때문에 long long 형으로 선언해야함
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end());
    for(int i=0; i<n-2; i++) {
        for(int j=i+1; j<n-1; j++) {
            int want = (vec[i] + vec[j]) * -1;
            int first = lower_bound(vec.begin()+j+1,vec.end(), want) - vec.begin();
            int second = upper_bound(vec.begin()+j+1,vec.end(), want) - vec.begin();
            count += second-first;
        }
    }
    cout << count;
}