#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, x, y;
    vector< pair<int, int> > arr;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x >> y;
        arr.push_back(make_pair(x,y));
    }
    sort(arr.begin(), arr.end());

    int st = arr[0].first, en = arr[0].second, len=0;
    for(int i=1; i<n; i++){
        if(en > arr[i].first){
            if(arr[i].second>en) en = arr[i].second;
        }
        else{
            len += (en-st);
            st = arr[i].first;
            en = arr[i].second;
        }
    }
    len += (en-st);
    cout << len << "\n";
}
