#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> vec;
    int n,m,a;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> a;
        vec.push_back(a);
    }
    int st = 0;
    int en = 1;
    int sum = vec[0];
    int count=0;
    while(1) {
        if(sum == m) {
            count++;
            if(en==vec.size()) break;
            sum += vec[en];
            en++;
        }
        else if(sum < m) {
            if(en==vec.size()) break;
            sum+=vec[en];
            en++;
        }
        else if(sum > m) {
            sum-=vec[st];
            st++;
        }
    }
    cout << count;


}