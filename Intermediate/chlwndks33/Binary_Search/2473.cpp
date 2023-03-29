#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long ansa, ansb,ansc;
    vector<long long> vec;
    int n;
    long long a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        vec.push_back(a);
    }
    ansa = vec[0];
    ansb = vec[1];
    ansc = vec[2];
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n-2; i++) {
        int st = i + 1;
        int en = n - 1;
        while(st<en) {
            if(vec[i]+vec[st]+vec[en] == 0) {
                ansa = vec[i];
                ansb = vec[st];
                ansc = vec[en];
                cout << ansa << " " << ansb << " " << ansc;
                return 0;
            }
            if(llabs(ansa+ansb+ansc) > llabs(vec[i]+vec[st] + vec[en])) {
                ansa = vec[i];
                ansb = vec[st];
                ansc = vec[en];
            }
            if(vec[i]+vec[st]+ vec[en] > 0) en--;
            else st++;
        }
    }
    cout << ansa << " " << ansb << " " << ansc;
}

