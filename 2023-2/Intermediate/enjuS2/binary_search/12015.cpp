#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<climits>
using namespace std;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        if (arr.empty() || arr.back() < input) {
            arr.push_back(input);
        }
        else {
            *lower_bound(arr.begin(), arr.end(), input) = input;
        }
    }
    cout << arr.size();
    return 0;
}
