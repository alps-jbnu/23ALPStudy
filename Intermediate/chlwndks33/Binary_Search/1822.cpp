#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> va;
    vector<int> vb;
    vector<int> ans;

    int a,b,x;
    cin >> a >> b;
    for(int i=0; i<a; i++) {
        cin >> x;
        va.push_back(x);
    } 
    for(int i=0; i<b; i++) {
        cin >> x;
        vb.push_back(x);
    }
    sort(va.begin(),va.end());
    sort(vb.begin(),vb.end());
    int count =0;
    for(int i=0; i<a; i++) {
        if(!binary_search(vb.begin(),vb.end(),va[i])) {
            ans.push_back(va[i]);
            count++;
        }
    }
    if(count) {
        cout << count << '\n';
        for(auto e : ans) cout<< e << " ";
    }
    else cout << "0";

}