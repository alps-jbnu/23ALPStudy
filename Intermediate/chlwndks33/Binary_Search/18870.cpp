#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> vec;
    vector<int> cp;
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        vec.push_back(a);
    }
    cp = vec;
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    for(int i=0; i<n; i++) {
        cout << lower_bound(vec.begin(),vec.end(),cp[i]) - vec.begin() << " ";
    }

}