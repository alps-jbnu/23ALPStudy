#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> vec;
    vector<int> vbi;
    int n,m;
    cin >> n;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(),vec.end());
    cin >> m;
    for(int i=0; i<m; i++) {
        int a;
        cin >> a;
        vbi.push_back(a);
    }
    for(int i=0; i<m; i++) {
        if(binary_search(vec.begin(),vec.end(),vbi[i])) cout << 1 <<'\n';
        else cout << 0 << '\n';
    }

}