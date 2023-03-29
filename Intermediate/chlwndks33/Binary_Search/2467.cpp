#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long ansa=2000000001;
    long ansb=2000000001;

    vector<int> vec;
    int n;
    int a;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a;
        vec.push_back(a);
    }
    int st = 0;
    int en = n-1;

    while(st<en) {
        if(vec[st]+vec[en] == 0) {
            ansa = vec[st];
            ansb = vec[en];
            break;
        }
        if(llabs(ansa+ansb) > llabs(vec[st]+vec[en])) {
                ansa = vec[st];
                ansb = vec[en];
        }
        if(vec[st]+ vec[en] > 0) en--;
        else st++;
    }
    cout << ansa << " " << ansb;
}