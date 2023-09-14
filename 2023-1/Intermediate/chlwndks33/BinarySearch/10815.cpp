#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> vec;

    int n,m,a,b;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(),vec.end());
    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> b;
        if(binary_search(vec.begin(),vec.end(),b)) cout << "1 ";
        else cout << "0 ";
    }
    return 0;
}